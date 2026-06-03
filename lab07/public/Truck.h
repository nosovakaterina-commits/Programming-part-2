#pragma once

#include "Vehicle.h"
#include <string>

class Truck : public Vehicle {
public:
    Truck(std::string brand, int powerHp, double weight, double maxLoadCapacity, int axleCount);

    ~Truck() override = default;                                 // Деструктор
    
    Truck(const Truck&) = delete;                                // Заборона копіювання
    Truck& operator=(const Truck&) = delete;                     // Заборона присвоювання
    
    Truck(Truck&&) = default;                                    // Дозвіл переміщення
    Truck& operator=(Truck&&) = default;                         // Дозвіл переміщення присвоюванням

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