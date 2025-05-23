#include "MaintenanceTask.h"

MaintenanceTask::MaintenanceTask(std::string name, std::string desc, std::vector<std::string> types)
    : taskName(name), description(desc), applicableTypes(types) {}

std::string MaintenanceTask::getTaskName() const { return taskName; }
std::string MaintenanceTask::getDescription() const { return description; }
const std::vector<std::string>& MaintenanceTask::getApplicableTypes() const { return applicableTypes; }
