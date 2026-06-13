#include <gtest/gtest.h>
#include "catalog.h"

// Тест базових операцій пошуку та унікальності
TEST(LibraryCatalogTestSuite, BasicContainerOperations) {
    std::vector<Book> testBooks = {
        {1, "The Hobbit", "J.R.R. Tolkien", 1937, true},
        {2, "1984", "George Orwell", 1949, true}
    };
    LibraryCatalog catalog(testBooks);

    EXPECT_EQ(catalog.getCatalogSize(), 2);
    EXPECT_TRUE(catalog.hasBook(1));
    EXPECT_EQ(catalog.getBookById(2).title, "1984");
}

// Тест групування даних та частотного аналізу
TEST(LibraryCatalogTestSuite, GroupingAndFrequencyOperations) {
    std::vector<Book> testBooks = {
        {1, "The Hobbit", "J.R.R. Tolkien", 1954, true},
        {2, "The Two Towers", "J.R.R. Tolkien", 1954, false}
    };
    LibraryCatalog catalog(testBooks);

    auto results = catalog.getBooksByAuthor("J.R.R. Tolkien");
    EXPECT_EQ(results.size(), 2);
    EXPECT_EQ(catalog.getBookCountByYear(1954), 2);
}

// Тест Розширення 
TEST(LibraryCatalogTestSuite, CustomKeyExtensionTest) {
    std::vector<Book> emptyList;
    LibraryCatalog catalog(emptyList);

    BookKey key1{"George Orwell", "1984"};
    catalog.addUniqueKey(key1);

    EXPECT_TRUE(catalog.hasUniqueKey(key1));
}

// Тест Розширення 
TEST(LibraryCatalogTestSuite, QueueAdapterExtensionTest) {
    std::vector<Book> emptyList;
    LibraryCatalog catalog(emptyList);

    catalog.pushRequest({1, "Alice", 10});
    catalog.pushRequest({2, "Bob", 12});

    EXPECT_EQ(catalog.getQueueSize(), 2);
    
    CheckoutRequest first = catalog.popRequest();
    EXPECT_EQ(first.readerName, "Alice");
    EXPECT_EQ(catalog.getQueueSize(), 1);
}