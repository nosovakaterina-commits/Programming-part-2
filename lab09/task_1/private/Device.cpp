#include "Device.h"
#include <iostream>
#include <utility>

Device::Device(std::string name) : deviceName(std::move(name)), isOn(false) {}

void Device::togglePower() {
    isOn = !isOn;
    std::cout << "[POWER] Device '" << deviceName << "' is now " 
              << (isOn ? "ON" : "OFF") << ".\n";
}