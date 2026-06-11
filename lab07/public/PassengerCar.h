#pragma once

#include "Vehicle.h"
#include <string>

class PassengerCar : public Vehicle {
public:
    PassengerCar(std::string brand, int powerHp, double weight, int passengerSeats, std::string bodyType);

    ~PassengerCar() override = default;                          // Явний деструктор
    
    PassengerCar(const PassengerCar&) = delete;                  // Заборона конструктора копіювання
    PassengerCar& operator=(const PassengerCar&) = delete;       // Заборона оператора присвоювання
    
    PassengerCar(PassengerCar&&) = default;                      // Дозвіл конструктора переміщення
    PassengerCar& operator=(PassengerCar&&) = default;           // Дозвіл оператора переміщення

    int passengerSeats() const;
    const std::string& bodyType() const;
    int totalTrips() const;

    void driveTrip();

    std::string category() const override;
    std::string statusLine() const override;

private:
    int passengerSeats_;
    std::string bodyType_;
    int totalTrips_;
};