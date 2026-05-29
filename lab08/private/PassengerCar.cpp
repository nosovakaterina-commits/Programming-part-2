#include "PassengerCar.h"
#include <sstream>
#include <utility>

PassengerCar::PassengerCar(std::string brand, int powerHp, double weight, int passengerSeats, std::string bodyType)
    : Vehicle(std::move(brand), powerHp, weight),
      passengerSeats_(passengerSeats), bodyType_(std::move(bodyType)), totalTrips_(0) {}

int PassengerCar::passengerSeats() const { return passengerSeats_; }
const std::string& PassengerCar::bodyType() const { return bodyType_; }
int PassengerCar::totalTrips() const { return totalTrips_; }

void PassengerCar::driveTrip() {
    totalTrips_ += 1;
}

std::string PassengerCar::category() const { return "PassengerCar"; }

std::string PassengerCar::statusLine() const {
    std::ostringstream out;
    out << Vehicle::statusLine() 
        << ", seats: " << passengerSeats_ << ", body: " << bodyType_
        << ", trips: " << totalTrips_;
    return out.str();
}