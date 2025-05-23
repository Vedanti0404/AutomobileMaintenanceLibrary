#include "Automobile.h"

Automobile::Automobile(std::string m, std::string mo, int y, int odo)
    : make(m), model(mo), year(y), odometerReading(odo) {}

std::string Automobile::getMake() const { return make; }
std::string Automobile::getModel() const { return model; }
int Automobile::getYear() const { return year; }
int Automobile::getOdometerReading() const { return odometerReading; }

ElectricCar::ElectricCar(std::string m, std::string mo, int y, int odo)
    : Automobile(m, mo, y, odo) {}
std::string ElectricCar::getType() const { return "electric"; }

GasCar::GasCar(std::string m, std::string mo, int y, int odo)
    : Automobile(m, mo, y, odo) {}
std::string GasCar::getType() const { return "gas"; }

DieselCar::DieselCar(std::string m, std::string mo, int y, int odo)
    : Automobile(m, mo, y, odo) {}
std::string DieselCar::getType() const { return "diesel"; }
