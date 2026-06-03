#include "Wheel.hpp"

Wheel::Wheel(int count)
    : count_(count),
      intact_(true) {}

int Wheel::getCount() const {
    return count_;
}

bool Wheel::isIntact() const {
    return intact_;
}

void Wheel::rotate() {
    if (!intact_) {
        return;
    }
}

void Wheel::repair() {
    if (intact_) {
        return;
    }
    intact_ = true;
}