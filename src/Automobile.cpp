#include "Automobile.hpp"

Automobile::Automobile(std::string make, std::string model, int year, int odometerReading, std::string type)
    : make(make), model(model), year(year), odometerReading(odometerReading), type(type) {}

std::string Automobile::getMake() const { return make; }
std::string Automobile::getModel() const { return model; }
int Automobile::getYear() const { return year; }
int Automobile::getOdometer() const { return odometerReading; }
std::string Automobile::getType() const { return type; }

ElectricCar::ElectricCar(std::string make, std::string model, int year, int odometerReading)
    : Automobile(make, model, year, odometerReading, "electric") {}

GasCar::GasCar(std::string make, std::string model, int year, int odometerReading)
    : Automobile(make, model, year, odometerReading, "gas") {}

DieselCar::DieselCar(std::string make, std::string model, int year, int odometerReading)
    : Automobile(make, model, year, odometerReading, "diesel") {}
