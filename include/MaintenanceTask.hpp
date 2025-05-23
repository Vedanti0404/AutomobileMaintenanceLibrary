#ifndef MAINTENANCETASK_HPP
#define MAINTENANCETASK_HPP

#include <string>
#include <vector>

class MaintenanceTask {
    std::string taskName;
    std::string description;
    std::vector<std::string> applicableVehicleTypes;

public:
    MaintenanceTask(std::string name, std::string desc, std::vector<std::string> applicableTypes);

    std::string getTaskName() const;
    std::string getDescription() const;
    std::vector<std::string> getApplicableTypes() const;
    bool isApplicableTo(const std::string& vehicleType) const;
};

#endif
