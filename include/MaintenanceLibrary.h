#pragma once
#include <vector>
#include <memory>
#include <map>
#include "Automobile.h"
#include "MaintenanceTask.h"

class MaintenanceLibrary {
    std::vector<std::shared_ptr<Automobile>> vehicles;
    std::map<std::shared_ptr<Automobile>, std::vector<MaintenanceTask>> maintenanceRecords;
public:
    void addVehicle(std::shared_ptr<Automobile> vehicle);
    void removeVehicle(std::shared_ptr<Automobile> vehicle);
    void listVehicles() const;

    void addMaintenanceTask(std::shared_ptr<Automobile> vehicle, const MaintenanceTask& task);
    void removeMaintenanceTask(std::shared_ptr<Automobile> vehicle, const std::string& taskName);
    void listMaintenanceTasks(std::shared_ptr<Automobile> vehicle) const;
};
