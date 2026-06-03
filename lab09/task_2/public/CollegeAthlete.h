#pragma once
#include "Student.h"
#include "Athlete.h"

// Похідний клас успадковує повний інтерфейс та стан як і у базових класах Student, Athlete.
class CollegeAthlete : public Student, public Athlete {
private:
    std::string athleteName;
    std::string collegeName;

public:
    CollegeAthlete(std::string name, std::string major, double gpa, 
                   std::string sport, int hours, std::string college);

    void showFullProfile() const;
};