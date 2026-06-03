#pragma once
#include "Device.h"

class InputDevice : virtual public Device
{
 // virtual для вирішення проблеми ромба.
protected:
    int updateRateHz;

public:
    InputDevice(std::string name, int rate);
    void describe() const override;
};