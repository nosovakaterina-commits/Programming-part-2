#pragma once

#include <string>

class Engine {
public:
    explicit Engine(int volumeMl = 2000);

    void start();
    void stop();
    void accelerate();
    void brake();

    bool isRunning() const;
    int getVolumeMl() const;
    int getRPM() const;
    int getSpeed() const;

private:
    int volumeMl_;
    int currentRPM_;
    int currentSpeed_;
    bool isRunning_;
};