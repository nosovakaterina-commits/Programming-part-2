#include "OutputDevice.h"
#include <iostream>
#include <utility>

OutputDevice::OutputDevice(std::string name, std::string res) 
    : Device(name), resolution(std::move(res)) {}

void OutputDevice::describe() const {
    std::cout << " -> Output Feature: Displaying at " << resolution << " resolution.\n";
}