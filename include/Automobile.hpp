#ifndef AUTOMOBILE_HPP
#define AUTOMOBILE_HPP

#include <string>

class Automobile {
protected:
    std::string make;
    std::string model;
    int year;
    int odometerReading;
    std::string type;

public:
    Automobile(std::string make, std::string model, int year, int odometerReading, std::string type);
    virtual ~Automobile() = default;

    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    int getOdometer() const;
    std::string getType() const;
};

class ElectricCar : public Automobile {
public:
    ElectricCar(std::string make, std::string model, int year, int odometerReading);
};

class GasCar : public Automobile {
public:
    GasCar(std::string make, std::string model, int year, int odometerReading);
};

class DieselCar : public Automobile {
public:
    DieselCar(std::string make, std::string model, int year, int odometerReading);
};

#endif
