cmake_minimum_required(VERSION 3.10)
project(AutomobileLibrary)

set(CMAKE_CXX_STANDARD 17)

# Add include directory for SQLite and your project headers
include_directories(include sqlite)

# Add sqlite3.c as a static library instead of using find_package
add_library(sqlite3 STATIC sqlite/sqlite3.c)

# Define your executable with all source files
add_executable(main
    src/main.cpp
    src/Automobile.cpp
    src/MaintenanceTask.cpp
    src/MaintenanceLibrary.cpp
)

# Link sqlite3 source directly (no .lib required)
target_link_libraries(main sqlite3)
