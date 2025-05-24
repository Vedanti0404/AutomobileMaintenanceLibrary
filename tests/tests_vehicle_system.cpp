#include <iostream>
#include <cassert>
#include "../Automobile.h"
#include "../MaintenanceLibrary.h"
#include "../MaintenanceTask.h"
#include "../Utils.h"

void testVehicleCreationAndType() {
    std::cout << "Running testVehicleCreationAndType...\n" << std::flush;

    ElectricCar ec("Tesla", "Model 3", 2022, 15000);
    GasCar gc("Toyota", "Corolla", 2019, 40000);
    DieselCar dc("Ford", "F-250", 2020, 30000);

    assert(ec.getType() == "Electric");
    assert(gc.getType() == "Gas");
    assert(dc.getType() == "Diesel");

    std::cout << "Passed: testVehicleCreationAndType\n" << std::flush;
}

void testToFromFileString() {
    std::cout << "Running testToFromFileString...\n" << std::flush;

    GasCar car("Honda", "Civic", 2018, 35000);
    std::string data = car.toFileString();

    Automobile* clone = Automobile::fromFileString(data);
    assert(clone != nullptr);
    assert(clone->getType() == "Gas");

    delete clone;

    std::cout << "Passed: testToFromFileString\n" << std::flush;
}

void testAddAndRemoveVehicle() {
    std::cout << "Running testAddAndRemoveVehicle...\n" << std::flush;

    MaintenanceLibrary lib;
    ElectricCar* ec = new ElectricCar("Nissan", "Leaf", 2021, 10000);
    lib.addVehicle(ec);
    lib.removeVehicle(0);

    std::cout << "Passed: testAddAndRemoveVehicle\n" << std::flush;
}

void testMaintenanceTaskFlow() {
    std::cout << "Running testMaintenanceTaskFlow...\n" << std::flush;

    MaintenanceLibrary lib;
    DieselCar* dc = new DieselCar("Chevy", "Silverado", 2020, 50000);
    lib.addVehicle(dc);

    lib.addMaintenanceTask(0, 3);
    lib.addMaintenanceTask(0, 2); // Shouldn't crash
    lib.removeMaintenanceTask(0);
    lib.removeVehicle(0);

    std::cout << "Passed: testMaintenanceTaskFlow\n" << std::flush;
}

int main() {
    std::cout << "Running Vehicle Maintenance System tests...\n" << std::flush;

    testVehicleCreationAndType();
    testToFromFileString();
    testAddAndRemoveVehicle();
    testMaintenanceTaskFlow();

    std::cout << "All tests passed successfully!\n" << std::flush;
    return 0;
}
