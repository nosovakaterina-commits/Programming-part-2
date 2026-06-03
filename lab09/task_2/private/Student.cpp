#include "Student.h"
#include <iostream>
#include <utility>

Student::Student(std::string studentMajor, double studentGpa) 
    : major(std::move(studentMajor)), gpa(studentGpa) {}

void Student::study() const {
    std::cout << " -> Academic status: Studying " << major << " with a current GPA of " << gpa << ".\n";
}

double Student::getGpa() const {
    return gpa;
}