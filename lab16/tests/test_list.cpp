#include <gtest/gtest.h>
#include "simple_forward_list.hpp"

// Тестування модифікації зв'язаного списку
TEST(SimpleForwardListTest, BasicOperations) {
    SimpleForwardList<int> l;
    EXPECT_TRUE(l.empty());

    l.push_front(30);
    l.push_front(40);
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l.front(), 40);

    auto it = l.begin();
    l.insert_after(it, 50);
    
    ++it;
    EXPECT_EQ(*it, 50);

    l.erase_after(l.begin());
    EXPECT_EQ(l.size(), 2);
}