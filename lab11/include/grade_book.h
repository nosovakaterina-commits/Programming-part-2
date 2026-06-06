#pragma once

#include <stdexcept>
#include <cstddef>

// Шаблон класу GradeBook з типом даних T та нетиповим параметром ємності N
template <typename T, std::size_t N>
class GradeBook {
private:
    T grades_[N];
    std::size_t count_ = 0;

public:
    GradeBook() = default;

    bool addGrade(const T& grade) {
        if (count_ >= N) {
            return false;
        }
        grades_[count_++] = grade;
        return true;
    }

    T get(std::size_t index) const {
        if (index >= count_) {
            throw std::out_of_range("Index out of range");
        }
        return grades_[index];
    }

    std::size_t count() const {
        return count_;
    }

    // Пошук найкращої (максимальної) оцінки
    T best() const {
        if (count_ == 0) {
            throw std::runtime_error("Grade book is empty");
        }
        T maxGrade = grades_[0];
        for (std::size_t i = 1; i < count_; ++i) {
            if (grades_[i] > maxGrade) {
                maxGrade = grades_[i];
            }
        }
        return maxGrade;
    }

    // Обчислення середнього балу
    double average() const {
        if (count_ == 0) {
            throw std::runtime_error("Grade book is empty");
        }
        double sum = 0;
        for (std::size_t i = 0; i < count_; ++i) {
            sum += static_cast<double>(grades_[i]);
        }
        return sum / count_;
    }

    // Максимальна можлива ємність книги оцінок 
    std::size_t capacity() const {
        return N;
    }
};