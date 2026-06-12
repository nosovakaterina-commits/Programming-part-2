#include <gtest/gtest.h>
#include "simple_vector.hpp"

// Тестування базових операцій додавання, видалення та індексації SimpleVector
TEST(SimpleVectorTest, BasicOperations) {
    SimpleVector<int> v;
    EXPECT_TRUE(v.empty());
    
    v.push_back(10);
    v.push_back(20);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v.back(), 20);

    v.pop_back();
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.back(), 10);
}