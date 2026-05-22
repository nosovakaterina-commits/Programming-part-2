#include "Seat.hpp"

Seat::Seat(int count)
    : count_(count),
      comfortable_(true) {}

int Seat::getCount() const {
    return count_;
}

bool Seat::isComfortable() const {
    return comfortable_;
}

void Seat::adjust() {
    if (!comfortable_) {
        comfortable_ = true;
    }
}

void Seat::clean() {
    comfortable_ = true;
}