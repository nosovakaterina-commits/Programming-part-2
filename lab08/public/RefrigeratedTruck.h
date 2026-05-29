#pragma once

#include "Truck.h"
#include <string>

class RefrigeratedTruck final : public Truck {
public:
    RefrigeratedTruck(std::string brand, int powerHp, double weight, 
                      double maxLoadCapacity, int axleCount, 
                      double minTemperature, bool isCoolingActive);

    double minTemperature() const;
    bool isCoolingActive() const;

    void setCooling(bool active);
    void deliveryFrozenGoods(int tons);

    std::string category() const override;
    std::string statusLine() const override;

private:
    double minTemperature_;
    bool isCoolingActive_;
};