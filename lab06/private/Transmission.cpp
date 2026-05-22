#include "Transmission.hpp"

Transmission::Transmission()
    : currentGear_("P"),
      inGear_(false) {}

std::string Transmission::getCurrentGear() const {
    return currentGear_;
}

bool Transmission::isInGear() const {
    return inGear_;
}

void Transmission::shiftUp() {
    if (currentGear_ == "P") {
        currentGear_ = "R";
        inGear_ = true;
    } else if (currentGear_ == "R") {
        currentGear_ = "N";
        inGear_ = false;
    } else if (currentGear_ == "N") {
        currentGear_ = "D";
        inGear_ = true;
    } else if (currentGear_ == "D") {
        currentGear_ = "S";
        inGear_ = true;
    }
}

void Transmission::shiftDown() {
    if (currentGear_ == "S") {
        currentGear_ = "D";
        inGear_ = true;
    } else if (currentGear_ == "D") {
        currentGear_ = "N";
        inGear_ = false;
    } else if (currentGear_ == "N") {
        currentGear_ = "R";
        inGear_ = true;
    } else if (currentGear_ == "R") {
        currentGear_ = "P";
        inGear_ = false;
    }
}

void Transmission::setNeutral() {
    currentGear_ = "N";
    inGear_ = false;
}