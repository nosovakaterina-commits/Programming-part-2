#include "Student_array.h"
#include <stdexcept>
#include <utility>

Student_array::Student_array(std::size_t size) : size_(size) {
    data_ = size_ > 0 ? new Student[size_]() : nullptr;
}

Student_array::~Student_array() {
    delete[] data_;
}

// Конструктор копіювання (Глибоке копіювання)
Student_array::Student_array(const Student_array& other) : size_(other.size_) {
    if (other.data_) {
        data_ = new Student[size_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    } else {
        data_ = nullptr;
    }
}

// Оператор копіюючого присвоювання
Student_array& Student_array::operator=(const Student_array& other) {
    if (this == &other) return *this;
    delete[] data_;

    size_ = other.size_;
    if (other.data_) {
        data_ = new Student[size_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    } else {
        data_ = nullptr;
    }
    return *this;
}

// Конструктор переміщення
Student_array::Student_array(Student_array&& other) noexcept 
    : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr;
    other.size_ = 0;
}

// Оператор переміщуючого присвоювання
Student_array& Student_array::operator=(Student_array&& other) noexcept {
    if (this == &other) return *this;
    delete[] data_;

    data_ = other.data_;
    size_ = other.size_;

    other.data_ = nullptr;
    other.size_ = 0;
    return *this;
}

Student& Student_array::at(std::size_t index) {
    if (index >= size_) throw std::out_of_range("Index out of bounds");
    return data_[index];
}

const Student& Student_array::at(std::size_t index) const {
    if (index >= size_) throw std::out_of_range("Index out of bounds");
    return data_[index];
}

std::size_t Student_array::size() const { return size_; }