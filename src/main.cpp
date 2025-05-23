#include "MaintenanceLibrary.hpp"
#include <memory>

int main() {
    MaintenanceLibrary library;

    auto car1 = std::make_shared<ElectricCar>("Tesla", "Model S", 2022, 12000);
    auto car2 = std::make_shared<GasCar>("Toyota", "Corolla", 2018, 60000);
    auto car3 = std::make_shared<DieselCar>("Ford", "F-250", 2015, 85000);

    library.addVehicle(car1);
    library.addVehicle(car2);
    library.addVehicle(car3);

    library.listVehicles();

    return 0;
}
