#pragma once

#include <string>

class Transmission {
public:
    explicit Transmission();

    std::string getCurrentGear() const;
    bool isInGear() const;
    
    void shiftUp();
    void shiftDown();
    void setNeutral();

private:
    std::string currentGear_;
    bool inGear_;
};