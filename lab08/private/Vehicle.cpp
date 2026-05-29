#include "Vehicle.h"
#include <sstream>
#include <utility>

Vehicle::Vehicle(std::string brand, int powerHp, double weight)
    : brand_(std::move(brand)), powerHp_(powerHp), weight_(weight) {}

const std::string& Vehicle::brand() const { return brand_; }
int Vehicle::powerHp() const { return powerHp_; }
double Vehicle::weight() const { return weight_; }

std::string Vehicle::category() const { return "Vehicle"; }

std::string Vehicle::statusLine() const {
    std::ostringstream out;
    out << category() << " " << brand_ << " (" << powerHp_ << " HP, " << weight_ << " t)";
    return out.str();
}