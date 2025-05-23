#include "../include/MaintenanceLibrary.h"
#include <iostream>

int main() {
    MaintenanceLibrary lib;
    auto car1 = std::make_shared<ElectricCar>("Tesla", "Model 3", 2022, 10000);
    auto car2 = std::make_shared<GasCar>("Toyota", "Corolla", 2021, 15000);

    lib.addVehicle(car1);
    lib.addVehicle(car2);
    lib.listVehicles();

    MaintenanceTask battery("Battery Inspection", "Check battery health", {"electric"});
    MaintenanceTask oil("Oil Change", "Change engine oil", {"gas", "diesel"});
    lib.addMaintenanceTask(car1, battery); // valid
    lib.addMaintenanceTask(car1, oil);     // not applicable
    lib.addMaintenanceTask(car2, oil);     // valid

    std::cout << "\nMaintenance for car1:\n";
    lib.listMaintenanceTasks(car1);
    std::cout << "\nMaintenance for car2:\n";
    lib.listMaintenanceTasks(car2);

    return 0;
}
