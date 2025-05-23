#pragma once
#include <string>

class Automobile {
protected:
    std::string make, model;
    int year, odometerReading;
public:
    Automobile(std::string make, std::string model, int year, int odometer);
    virtual std::string getType() const = 0;
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    int getOdometerReading() const;
    virtual ~Automobile() = default;
};

class ElectricCar : public Automobile {
public:
    ElectricCar(std::string make, std::string model, int year, int odometer);
    std::string getType() const override;
};

class GasCar : public Automobile {
public:
    GasCar(std::string make, std::string model, int year, int odometer);
    std::string getType() const override;
};

class DieselCar : public Automobile {
public:
    DieselCar(std::string make, std::string model, int year, int odometer);
    std::string getType() const override;
};
