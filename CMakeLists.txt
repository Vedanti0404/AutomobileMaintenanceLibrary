cmake_minimum_required(VERSION 3.10)
project(AutomobileLibrary)

set(CMAKE_CXX_STANDARD 17)

include_directories(include sqlite)

add_library(sqlite3 STATIC sqlite/sqlite3.c)

add_executable(main
    src/main.cpp
    src/Automobile.cpp
    src/MaintenanceTask.cpp
    src/MaintenanceLibrary.cpp
)

target_link_libraries(main sqlite3)
