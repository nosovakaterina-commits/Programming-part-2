#pragma once
#include "InputDevice.h"
#include "OutputDevice.h"

//  Похідний клас успадковує повний інтерфейс та стан як і у базових класах InputDevice, OutputDevice.
class TouchDisplay : public InputDevice, public OutputDevice
{
public:
    TouchDisplay(std::string name, int rate, std::string res);

    void describe() const override;
};