#include <gtest/gtest.h>
#include <algorithm>
#include <numeric>
#include "BookCatalog.hpp"

// Тест для перевірки функтора масштабування років
TEST(BookCatalogTests, FunctorStateTest) {
    BookRatingScaler scaler(0.5);
    EXPECT_DOUBLE_EQ(scaler(2000), 1000.0);
}

// Тест для перевірки алгоритму пошуку та підрахунку елементів
TEST(BookCatalogTests, SearchAndCountTest) {
    std::vector<Book> testBooks = {
        {1, "Book A", "Author X", 2005, true},
        {2, "Book B", "Author Y", 2015, false},
        {3, "Book C", "Author X", 2020, true}
    };

    // Перевірка std::count_if (кількість книг після 2010 року)
    int count = std::count_if(testBooks.begin(), testBooks.end(), [](const Book& b) {
        return b.year > 2010;
    });
    EXPECT_EQ(count, 2);

    // Перевірка std::find_if
    auto it = std::find_if(testBooks.begin(), testBooks.end(), [](const Book& b) {
        return b.available && b.author == "Author X";
    });
    ASSERT_NE(it, testBooks.end());
    EXPECT_EQ(it->id, 1);
}

// Тест для перевірки ідіоми Erase-Remove
TEST(BookCatalogTests, EraseRemoveIdiomTest) {
    std::vector<Book> testBooks = {
        {1, "Book A", "Author X", 2005, false},
        {2, "Book B", "Author Y", 2015, true},
        {3, "Book C", "Author X", 2020, false}
    };

    testBooks.erase(
        std::remove_if(testBooks.begin(), testBooks.end(), [](const Book& b) {
            return !b.available;
        }),
        testBooks.end()
    );

    // Після видалення має залишитися лише 1 доступна книга
    EXPECT_EQ(testBooks.size(), 1);
    EXPECT_EQ(testBooks[0].id, 2);
}