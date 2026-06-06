#pragma once
#include <cstddef>
#include "Student.h"

class Student_array
{
private:
    Student *data_;    // Сирий вказівник на динамічний масив об'єктів
    std::size_t size_; // Поточний розмір масиву

public:
    explicit Student_array(std::size_t size); // Конструктор із виділенням пам'яті
    ~Student_array();                         // Деструктор

    // Правило п'яти
    Student_array(const Student_array &other);                // Конструктор копіювання (Глибоке копіювання)
    Student_array &operator=(const Student_array &other);     // Оператор копіюючого присвоювання
    Student_array(Student_array &&other) noexcept;            // Конструктор переміщення
    Student_array &operator=(Student_array &&other) noexcept; // Оператор переміщуючого присвоювання

    // Перевірка меж
    Student &at(std::size_t index);
    const Student &at(std::size_t index) const;

    std::size_t size() const;
};