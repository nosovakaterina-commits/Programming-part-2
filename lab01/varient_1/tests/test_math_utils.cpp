#include <gtest/gtest.h>
#include "math_utils.hpp"

TEST(MathUtilsTest, AddWorks) {
    EXPECT_EQ(add(4, 8), 12);
}

TEST(MathUtilsTest, SubWorks) {
    EXPECT_EQ(sub(9, 7), 2);
}

TEST(MathUtilsTest, MulWorks) {
    EXPECT_EQ(mul(3, 24), 72);
}

TEST(MathUtilsTest, DivWorks) {
    EXPECT_EQ(divide(15, 3), 5);
}