#pragma once

#include <cstddef>
#include <stdexcept>

namespace measurement
{

    template <typename T>
    T maxValue(T a, T b)
    {
        return (a < b) ? b : a;
    }

    template <typename T>
    T minValue(T a, T b)
    {
        return (a < b) ? a : b;
    }

    template <typename T>
    T clampValue(T value, T low, T high)
    {
        if (high < low)
        {
            throw std::invalid_argument("clampValue: low cannot be greater than high");
        }
        if (value < low)
            return low;
        if (high < value)
            return high;
        return value;
    }

    template <typename T>
    double average(const T *arr, std::size_t size)
    {
        if (!arr || size == 0)
        {
            throw std::invalid_argument("average: array cannot be null or empty");
        }

        T sum = T();
        for (std::size_t i = 0; i < size; ++i)
        {
            sum += arr[i];
        }

        return static_cast<double>(sum) / static_cast<double>(size);
    }

}