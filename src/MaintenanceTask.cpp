#include "MaintenanceTask.hpp"

MaintenanceTask::MaintenanceTask(std::string name, std::string desc, std::vector<std::string> applicableTypes)
    : taskName(name), description(desc), applicableVehicleTypes(applicableTypes) {}

std::string MaintenanceTask::getTaskName() const { return taskName; }
std::string MaintenanceTask::getDescription() const { return description; }
std::vector<std::string> MaintenanceTask::getApplicableTypes() const { return applicableVehicleTypes; }

bool MaintenanceTask::isApplicableTo(const std::string& vehicleType) const {
    return std::find(applicableVehicleTypes.begin(), applicableVehicleTypes.end(), vehicleType) != applicableVehicleTypes.end();
}
