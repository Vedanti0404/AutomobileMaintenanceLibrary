#include "MaintenanceLibrary.hpp"
#include <iostream>

MaintenanceLibrary::MaintenanceLibrary() {
    if (sqlite3_open("maintenance.db", &db)) {
        std::cerr << "Database open failed\n";
    } else {
        createTables();
        loadVehiclesFromDB();
    }
}

MaintenanceLibrary::~MaintenanceLibrary() {
    sqlite3_close(db);
}

void MaintenanceLibrary::createTables() {
    const char* vehicleSQL = R"(
        CREATE TABLE IF NOT EXISTS Vehicles (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            make TEXT,
            model TEXT,
            year INTEGER,
            odometer INTEGER,
            type TEXT
        );
    )";

    char* errMsg;
    if (sqlite3_exec(db, vehicleSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Error creating table: " << errMsg << "\n";
        sqlite3_free(errMsg);
    }
}

void MaintenanceLibrary::addVehicle(std::shared_ptr<Automobile> vehicle) {
    vehicles.push_back(vehicle);
    addVehicleToDB(vehicle);
}

void MaintenanceLibrary::addVehicleToDB(std::shared_ptr<Automobile> vehicle) {
    std::string sql = "INSERT INTO Vehicles (make, model, year, odometer, type) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, vehicle->getMake().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, vehicle->getModel().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 3, vehicle->getYear());
        sqlite3_bind_int(stmt, 4, vehicle->getOdometer());
        sqlite3_bind_text(stmt, 5, vehicle->getType().c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE)
            std::cerr << "Error inserting vehicle.\n";
        sqlite3_finalize(stmt);
    }
}

void MaintenanceLibrary::loadVehiclesFromDB() {
    std::string sql = "SELECT make, model, year, odometer, type FROM Vehicles;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string make = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            std::string model = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            int year = sqlite3_column_int(stmt, 2);
            int odo = sqlite3_column_int(stmt, 3);
            std::string type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

            if (type == "electric")
                vehicles.push_back(std::make_shared<ElectricCar>(make, model, year, odo));
            else if (type == "gas")
                vehicles.push_back(std::make_shared<GasCar>(make, model, year, odo));
            else if (type == "diesel")
                vehicles.push_back(std::make_shared<DieselCar>(make, model, year, odo));
        }
        sqlite3_finalize(stmt);
    }
}

void MaintenanceLibrary::listVehicles() const {
    for (const auto& v : vehicles) {
        std::cout << v->getType() << " | " << v->getMake() << " " << v->getModel()
                  << " (" << v->getYear() << ") - Odometer: " << v->getOdometer() << "\n";
    }
}
