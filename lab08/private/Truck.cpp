#include "Truck.h"
#include <sstream>
#include <stdexcept>
#include <utility>

Truck::Truck(std::string brand, int powerHp, double weight, double maxLoadCapacity, int axleCount)
    : Vehicle(std::move(brand), powerHp, weight), 
      maxLoadCapacity_(maxLoadCapacity), axleCount_(axleCount), totalCargoTransported_(0) {}

double Truck::maxLoadCapacity() const { return maxLoadCapacity_; }
int Truck::axleCount() const { return axleCount_; }
int Truck::totalCargoTransported() const { return totalCargoTransported_; }

void Truck::transportCargo(int tons) {
    if (tons <= 0) {
        throw std::invalid_argument("tons must be positive");
    }
    totalCargoTransported_ += tons;
}

std::string Truck::category() const { return "Truck"; }

std::string Truck::statusLine() const {
    std::ostringstream out;
    out << Vehicle::statusLine() 
        << ", max load: " << maxLoadCapacity_ << " t, axles: " << axleCount_
        << ", total transported: " << totalCargoTransported_ << " t";
    return out.str();
}