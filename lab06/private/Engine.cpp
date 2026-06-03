#include "Engine.hpp"

Engine::Engine(int volumeMl)
    : volumeMl_(volumeMl),
      currentRPM_(0),
      currentSpeed_(0),
      isRunning_(false) {}

void Engine::start() {
    if (isRunning_) {
        return;
    }
    isRunning_ = true;
    currentRPM_ = 1000;
}

void Engine::stop() {
    if (!isRunning_) {
        return;
    }
    isRunning_ = false;
    currentRPM_ = 0;
    currentSpeed_ = 0;
}

void Engine::accelerate() {
    if (!isRunning_) {
        return;
    }
    if (currentRPM_ < 7000) {
        currentRPM_ += 500;
        currentSpeed_ += 10;
    }
}

void Engine::brake() {
    if (!isRunning_) {
        return;
    }
    if (currentRPM_ > 1000) {
        currentRPM_ -= 500;
        currentSpeed_ -= 10;
    }
    if (currentSpeed_ < 0) {
        currentSpeed_ = 0;
    }
}

bool Engine::isRunning() const {
    return isRunning_;
}

int Engine::getVolumeMl() const {
    return volumeMl_;
}

int Engine::getRPM() const {
    return currentRPM_;
}

int Engine::getSpeed() const {
    return currentSpeed_;
}