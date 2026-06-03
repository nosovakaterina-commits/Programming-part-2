#pragma once

#include <string>

#include "Engine.hpp"
#include "Transmission.hpp"
#include "Seat.hpp"
#include "Wheel.hpp"

class Car {
public:
    Car(int engineVolumeMl = 2000, int wheelsCount = 4);

    void startEngine();
    void stopEngine();
    void accelerate();
    void brake();

    bool isEngineRunning() const;
    int getSpeed() const;
    int getEngineRPM() const;
    const std::string& getStatusMessage() const;

    void refuel(int fuelAmount);
    int getRemainingFuel() const;

private:
    void validateEngineState() const;

    Engine engine_;
    Transmission transmission_;
    Seat seats_;
    Wheel wheels_;

    int currentSpeed_;
    int currentFuel_;
    std::string statusMessage_;
};