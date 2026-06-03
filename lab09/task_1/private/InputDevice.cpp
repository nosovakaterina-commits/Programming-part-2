#include "InputDevice.h"
#include <iostream>

InputDevice::InputDevice(std::string name, int rate) 
    : Device(name), updateRateHz(rate) {}

void InputDevice::describe() const {
    std::cout << " -> Input Feature: Scanning at " << updateRateHz << " Hz.\n";
}