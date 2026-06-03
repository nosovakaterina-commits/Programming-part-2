#pragma once
#include <string>

class Student {
protected:
    std::string major; // Спеціальність
    double gpa;        // Середній балл

public:
    Student(std::string studentMajor, double studentGpa);
    virtual ~Student() = default; // Віртуальний деструктор для безпечного поліморфізму

    void study() const;
    double getGpa() const;
};