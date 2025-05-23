#pragma once
#include <string>
#include <vector>

class MaintenanceTask {
    std::string taskName;
    std::string description;
    std::vector<std::string> applicableTypes;
public:
    MaintenanceTask(std::string name, std::string desc, std::vector<std::string> types);
    std::string getTaskName() const;
    std::string getDescription() const;
    const std::vector<std::string>& getApplicableTypes() const;
};
