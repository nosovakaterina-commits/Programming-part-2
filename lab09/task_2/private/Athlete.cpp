#include "Athlete.h"
#include <iostream>
#include <utility>

Athlete::Athlete(std::string sport, int hours) 
    : sportType(std::move(sport)), hoursPerWeek(hours) {}

void Athlete::train() const {
    std::cout << " -> Athletic status: Training hard in " << sportType << " for " << hoursPerWeek << " hours a week.\n";
}

std::string Athlete::getSportType() const {
    return sportType;
}