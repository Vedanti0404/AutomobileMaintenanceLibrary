#ifndef MAINTENANCELIBRARY_HPP
#define MAINTENANCELIBRARY_HPP

#include "Automobile.hpp"
#include "MaintenanceTask.hpp"
#include <vector>
#include <memory>
#include <sqlite3.h>

class MaintenanceLibrary {
    sqlite3* db;
    std::vector<std::shared_ptr<Automobile>> vehicles;

    void createTables();
    void loadVehiclesFromDB();

public:
    MaintenanceLibrary();
    ~MaintenanceLibrary();

    void addVehicle(std::shared_ptr<Automobile> vehicle);
    void listVehicles() const;
    void addVehicleToDB(std::shared_ptr<Automobile> vehicle);
};

#endif
