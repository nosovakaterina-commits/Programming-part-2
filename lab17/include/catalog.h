#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "book.h"

// Клас-каталог для керування асоціативними контейнерами
class LibraryCatalog
{
private:
    std::map<int, Book> indexById;
    std::set<std::string> uniqueAuthors;
    std::multimap<std::string, Book> groupingByAuthor;
    std::unordered_map<int, int> frequencyByYear;

    std::unordered_set<BookKey, BookKeyHash, BookKeyEqual> uniqueBookKeys;
    std::queue<CheckoutRequest> checkoutQueue;

public:
    LibraryCatalog(const std::vector<Book> &books);

    // Методи базового завдання
    bool addBook(const Book &book);
    bool removeBook(int id);
    const Book &getBookById(int id) const;
    bool hasBook(int id) const;
    std::vector<Book> getBooksByAuthor(const std::string &author) const;
    int getBookCountByYear(int year) const;
    size_t getUniqueAuthorsCount() const;
    size_t getCatalogSize() const;

    // Методи Розширення
    void addUniqueKey(const BookKey &key);
    bool hasUniqueKey(const BookKey &key) const;

    // Методи Розширення
    void pushRequest(const CheckoutRequest &request);
    CheckoutRequest popRequest();
    size_t getQueueSize() const;
};

#endif