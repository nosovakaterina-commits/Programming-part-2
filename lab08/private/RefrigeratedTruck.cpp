#include "RefrigeratedTruck.h"
#include <sstream>
#include <stdexcept>
#include <utility>

RefrigeratedTruck::RefrigeratedTruck(std::string brand, int powerHp, double weight, 
                                     double maxLoadCapacity, int axleCount, 
                                     double minTemperature, bool isCoolingActive)
    : Truck(std::move(brand), powerHp, weight, maxLoadCapacity, axleCount),
      minTemperature_(minTemperature), isCoolingActive_(isCoolingActive) {}

double RefrigeratedTruck::minTemperature() const { return minTemperature_; }
bool RefrigeratedTruck::isCoolingActive() const { return isCoolingActive_; }

void RefrigeratedTruck::setCooling(bool active) { isCoolingActive_ = active; }

void RefrigeratedTruck::deliveryFrozenGoods(int tons) {
    if (tons <= 0) {
        throw std::invalid_argument("tons must be positive");
    }
    if (!isCoolingActive_) {
        throw std::runtime_error("cooling is inactive, cannot deliver frozen goods");
    }
    transportCargo(tons);
}

std::string RefrigeratedTruck::category() const { return "RefrigeratedTruck"; }

std::string RefrigeratedTruck::statusLine() const {
    std::ostringstream out;
    out << Truck::statusLine() 
        << ", temp: " << minTemperature_ << " C, cooling: " << (isCoolingActive_ ? "yes" : "no");
    return out.str();
}