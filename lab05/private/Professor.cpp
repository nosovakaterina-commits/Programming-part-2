#include "Professor.hpp"

Professor::Professor() 
    : name("Unnamed professor"), averageSalary(0.0), courseTitle("None") {}

Professor::Professor(const char* name, double averageSalary, const char* courseTitle)
    : name(name), 
      averageSalary(averageSalary >= 0.0 ? averageSalary : 0.0), 
      courseTitle(courseTitle) {}

const char* Professor::getName() const { 
    return name; 
}

double Professor::getAverageSalary() const { 
    return averageSalary; 
}

const char* Professor::getCourseTitle() const { 
    return courseTitle; 
}

void Professor::setAverageSalary(double value) {
    if (value >= 0.0) {
        averageSalary = value;
    }
}

void Professor::setCourseTitle(const char* newCourseTitle) {
    courseTitle = newCourseTitle;
}