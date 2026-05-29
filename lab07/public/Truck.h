#pragma once

#include "Vehicle.h"
#include <string>

class Truck : public Vehicle {
public:
    Truck(std::string brand, int powerHp, double weight, double maxLoadCapacity, int axleCount);

    double maxLoadCapacity() const;
    int axleCount() const;
    int totalCargoTransported() const;

    void transportCargo(int tons);

    std::string category() const override;
    std::string statusLine() const override;

protected:
    double maxLoadCapacity_;
    int axleCount_;
    int totalCargoTransported_;
};