#pragma once

#include <string>

class Vehicle {
public:
    Vehicle(std::string brand, int powerHp, double weight);
    virtual ~Vehicle() = default;

    Vehicle(const Vehicle&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = default;
    Vehicle& operator=(Vehicle&&) = default;

    const std::string& brand() const;
    int powerHp() const;
    double weight() const;

    virtual std::string category() const;
    virtual std::string statusLine() const = 0;

protected:
    std::string brand_;
    int powerHp_;
    double weight_;
};