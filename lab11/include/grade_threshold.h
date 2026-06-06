#pragma once

// Базовий шаблон для цілих оцінок (int)
template <typename T>
struct GradeThreshold {
    static constexpr T pass() { return static_cast<T>(60); }
    static constexpr T excellent() { return static_cast<T>(90); }
};

// Повна спеціалізація шаблону для типу double
template <>
struct GradeThreshold<double> {
    static constexpr double pass() { return 60.0; }
    static constexpr double excellent() { return 90.0; }
};