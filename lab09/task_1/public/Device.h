#pragma once
#include <string>

class Device
{
protected:
    std::string deviceName;
    bool isOn;

public:
    Device(std::string name);
    virtual ~Device() = default;

    void togglePower();

    virtual void describe() const = 0;
};