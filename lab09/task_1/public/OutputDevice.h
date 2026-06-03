#pragma once
#include "Device.h"

class OutputDevice : virtual public Device
{ 
    // virtual для спільної бази.
protected:
    std::string resolution;

public:
    OutputDevice(std::string name, std::string res);
    void describe() const override;
};