#include "MaintenanceLibrary.h"
#include <algorithm>
#include <iostream>

void MaintenanceLibrary::addVehicle(std::shared_ptr<Automobile> vehicle) {
    vehicles.push_back(vehicle);
}

void MaintenanceLibrary::removeVehicle(std::shared_ptr<Automobile> vehicle) {
    vehicles.erase(std::remove(vehicles.begin(), vehicles.end(), vehicle), vehicles.end());
    maintenanceRecords.erase(vehicle);
}

void MaintenanceLibrary::listVehicles() const {
    for (const auto& v : vehicles) {
        std::cout << v->getType() << ": " << v->getMake() << " " << v->getModel() << " (" << v->getYear() << ")\n";
    }
}

void MaintenanceLibrary::addMaintenanceTask(std::shared_ptr<Automobile> vehicle, const MaintenanceTask& task) {
    for (const auto& type : task.getApplicableTypes()) {
        if (type == vehicle->getType()) {
            maintenanceRecords[vehicle].push_back(task);
            return;
        }
    }
    std::cout << "Task \"" << task.getTaskName() << "\" not applicable for " << vehicle->getType() << "\n";
}

void MaintenanceLibrary::removeMaintenanceTask(std::shared_ptr<Automobile> vehicle, const std::string& taskName) {
    auto& tasks = maintenanceRecords[vehicle];
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                [&](const MaintenanceTask& task) { return task.getTaskName() == taskName; }),
                tasks.end());
}

void MaintenanceLibrary::listMaintenanceTasks(std::shared_ptr<Automobile> vehicle) const {
    auto it = maintenanceRecords.find(vehicle);
    if (it != maintenanceRecords.end()) {
        for (const auto& task : it->second) {
            std::cout << "- " << task.getTaskName() << ": " << task.getDescription() << "\n";
        }
    } else {
        std::cout << "No maintenance tasks found.\n";
    }
}
