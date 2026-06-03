#include "CollegeAthlete.h"
#include <iostream>
#include <utility>

// Використовуємо список ініціалізації для паралельного виклику конструкторів обох незалежних батьківських класів.
CollegeAthlete::CollegeAthlete(std::string name, std::string major, double gpa, 
                               std::string sport, int hours, std::string college)
    : Student(std::move(major), gpa),           // Ініціалізуємо базовий клас Student
      Athlete(std::move(sport), hours),         // Ініціалізуємо базовий клас Athlete
      athleteName(std::move(name)), 
      collegeName(std::move(college)) 
{}

// Послідовно викликаємо методи базових класів для демонстрації поєднання двох незалежних ролей.
void CollegeAthlete::showFullProfile() const {
    std::cout << "College Athlete Profile: " << athleteName << "\n";
    std::cout << "University: " << collegeName << "\n";
    
    // Прямий виклик методів базових гілок наслідування.
    study(); 
    train();
}