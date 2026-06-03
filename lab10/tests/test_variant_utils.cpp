#include <gtest/gtest.h>
#include "variant_utils.h"

TEST(MeasurementUtilsTest, MaxValueHandlesIntAndDouble) {
    EXPECT_EQ(measurement::maxValue(10, 20), 20);
    EXPECT_DOUBLE_EQ(measurement::maxValue(3.14, 2.71), 3.14);
}

TEST(MeasurementUtilsTest, MinValueHandlesIntAndDouble) {
    EXPECT_EQ(measurement::minValue(10, 20), 10);
    EXPECT_DOUBLE_EQ(measurement::minValue(3.14, 2.71), 2.71);
}

TEST(MeasurementUtilsTest, ClampValueWithinInterval) {
    EXPECT_EQ(measurement::clampValue(15, 10, 20), 15);
}

TEST(MeasurementUtilsTest, ClampValueThrowsOnInvalidInterval) {
    EXPECT_THROW(measurement::clampValue(10, 20, 10), std::invalid_argument);
}

TEST(MeasurementUtilsTest, AverageComputesCorrectly) {
    int int_arr[] = {10, 20, 30, 40};
    EXPECT_DOUBLE_EQ(measurement::average(int_arr, 4), 25.0);
}

TEST(MeasurementUtilsTest, AverageThrowsOnInvalidInput) {
    int* null_arr = nullptr;
    EXPECT_THROW(measurement::average(null_arr, 2), std::invalid_argument);
}