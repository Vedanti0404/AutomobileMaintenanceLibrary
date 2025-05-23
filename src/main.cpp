#include "Automobile.h"
#include "MaintenanceTask.h"
#include "MaintenanceLibrary.h"
#include <iostream>
#include <memory>

void showMenu() {
    std::cout << "\n========== Automobile Maintenance Menu ==========\n";
    std::cout << "1. Add Vehicle\n";
    std::cout << "2. Remove Vehicle\n";
    std::cout << "3. List Vehicles\n";
    std::cout << "4. Add Maintenance Task\n";
    std::cout << "5. Remove Maintenance Task\n";
    std::cout << "6. List Maintenance Tasks for a Vehicle\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

std::shared_ptr<Automobile> createVehicle() {
    std::string type, make, model;
    int year, odo;
    std::cout << "Enter vehicle type (electric/gas/diesel): ";
    std::cin >> type;
    std::cout << "Enter make: ";
    std::cin >> make;
    std::cout << "Enter model: ";
    std::cin >> model;
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "Enter odometer reading: ";
    std::cin >> odo;

    if (type == "electric") {
        return std::make_shared<ElectricCar>(make, model, year, odo);
    } else if (type == "gas") {
        return std::make_shared<GasCar>(make, model, year, odo);
    } else if (type == "diesel") {
        return std::make_shared<DieselCar>(make, model, year, odo);
    } else {
        std::cout << "Invalid vehicle type.\n";
        return nullptr;
    }
}

int main() {
    MaintenanceLibrary lib;
    std::vector<std::shared_ptr<Automobile>> vehicleList;

    int choice;
    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1: {
                auto vehicle = createVehicle();
                if (vehicle) {
                    lib.addVehicle(vehicle);
                    vehicleList.push_back(vehicle);
                }
                break;
            }
            case 2: {
                std::string make, model;
                std::cout << "Enter make and model of the vehicle to remove: ";
                std::cin >> make >> model;
                bool found = false;
                for (auto it = vehicleList.begin(); it != vehicleList.end(); ++it) {
                    if ((*it)->getMake() == make && (*it)->getModel() == model) {
                        lib.removeVehicle(*it);
                        vehicleList.erase(it);
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Vehicle not found.\n";
                break;
            }
            case 3: {
                lib.listVehicles();
                break;
            }
            case 4: {
                std::string make, model;
                std::cout << "Enter vehicle make and model: ";
                std::cin >> make >> model;
                std::shared_ptr<Automobile> selected = nullptr;
                for (const auto& v : vehicleList) {
                    if (v->getMake() == make && v->getModel() == model) {
                        selected = v;
                        break;
                    }
                }
                if (!selected) {
                    std::cout << "Vehicle not found.\n";
                    break;
                }

                std::string name, desc;
                int numTypes;
                std::vector<std::string> types;
                std::cout << "Enter task name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter task description: ";
                std::getline(std::cin, desc);
                std::cout << "Enter number of applicable vehicle types: ";
                std::cin >> numTypes;
                std::cin.ignore();
                for (int i = 0; i < numTypes; ++i) {
                    std::string t;
                    std::cout << "Enter type " << i + 1 << " (electric/gas/diesel): ";
                    std::getline(std::cin, t);
                    types.push_back(t);
                }

                MaintenanceTask task(name, desc, types);
                lib.addMaintenanceTask(selected, task);
                break;
            }
            case 5: {
                std::string make, model, taskName;
                std::cout << "Enter vehicle make and model: ";
                std::cin >> make >> model;
                std::cin.ignore();
                std::cout << "Enter task name to remove: ";
                std::getline(std::cin, taskName);

                std::shared_ptr<Automobile> selected = nullptr;
                for (const auto& v : vehicleList) {
                    if (v->getMake() == make && v->getModel() == model) {
                        selected = v;
                        break;
                    }
                }
                if (!selected) {
                    std::cout << "Vehicle not found.\n";
                    break;
                }

                lib.removeMaintenanceTask(selected, taskName);
                break;
            }
            case 6: {
                std::string make, model;
                std::cout << "Enter vehicle make and model: ";
                std::cin >> make >> model;
                std::shared_ptr<Automobile> selected = nullptr;
                for (const auto& v : vehicleList) {
                    if (v->getMake() == make && v->getModel() == model) {
                        selected = v;
                        break;
                    }
                }
                if (!selected) {
                    std::cout << "Vehicle not found.\n";
                    break;
                }

                lib.listMaintenanceTasks(selected);
                break;
            }
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
