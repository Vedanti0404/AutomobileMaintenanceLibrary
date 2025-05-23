cmake_minimum_required(VERSION 3.10)
project(AutomobileMaintenanceLibrary)

set(CMAKE_CXX_STANDARD 17)

# Make sure compiler can find headers in the "include" directory
include_directories(include)

# Main application
add_executable(main
    src/main.cpp
    src/Automobile.cpp
    src/MaintenanceTask.cpp
    src/MaintenanceLibrary.cpp
)

# Unit tests
add_executable(unit_tests
    tests/test.cpp
    src/Automobile.cpp
    src/MaintenanceTask.cpp
    src/MaintenanceLibrary.cpp
)

enable_testing()
add_test(NAME RunTests COMMAND unit_tests)
