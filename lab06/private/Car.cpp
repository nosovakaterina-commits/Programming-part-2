#include "Car.hpp"
#include <stdexcept>

Car::Car(int engineVolumeMl, int wheelsCount)
    : engine_(engineVolumeMl),
      transmission_(),
      seats_(5),
      wheels_(wheelsCount),
      currentSpeed_(0),
      currentFuel_(60),
      statusMessage_("Car is ready.") {}

void Car::startEngine() {
    validateEngineState();
    engine_.start();
    statusMessage_ = "Engine started.";
}

void Car::stopEngine() {
    validateEngineState();
    engine_.stop();
    currentSpeed_ = 0;
    statusMessage_ = "Engine stopped.";
}

void Car::accelerate() {
    validateEngineState();
    if (!engine_.isRunning()) {
        statusMessage_ = "Cannot accelerate: engine is not running.";
        return;
    }
    engine_.accelerate();
    currentSpeed_ = engine_.getSpeed();
    currentFuel_--;
    statusMessage_ = "Car accelerated. Speed: " + std::to_string(currentSpeed_) + " km/h";
}

void Car::brake() {
    validateEngineState();
    if (!engine_.isRunning()) {
        statusMessage_ = "Cannot brake: engine is not running.";
        return;
    }
    engine_.brake();
    currentSpeed_ = engine_.getSpeed();
    statusMessage_ = "Car braked. Speed: " + std::to_string(currentSpeed_) + " km/h";
}

bool Car::isEngineRunning() const {
    return engine_.isRunning();
}

int Car::getSpeed() const {
    return currentSpeed_;
}

int Car::getEngineRPM() const {                    // ← ДОБАВЬ ЭТУ ФУНКЦИЮ
    return engine_.getRPM();
}

const std::string& Car::getStatusMessage() const {
    return statusMessage_;
}

void Car::refuel(int fuelAmount) {
    if (fuelAmount < 0) {
        statusMessage_ = "Invalid fuel amount.";
        return;
    }
    currentFuel_ += fuelAmount;
    if (currentFuel_ > 60) {
        currentFuel_ = 60;
    }
    statusMessage_ = "Car refueled. Current fuel: " + std::to_string(currentFuel_) + " L";
}

int Car::getRemainingFuel() const {
    return currentFuel_;
}

void Car::validateEngineState() const {
    if (currentFuel_ <= 0) {
        throw std::runtime_error("Not enough fuel to operate the car.");
    }
}