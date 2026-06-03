#pragma once
#include <string>

class Athlete {
protected:
    std::string sportType; // Вид спорту 
    int hoursPerWeek;      // Кількість годин тренувань на тиждень

public:
    Athlete(std::string sport, int hours);
    virtual ~Athlete() = default;

    void train() const;
    std::string getSportType() const;
};