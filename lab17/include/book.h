#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book
{
    int id;
    std::string title;
    std::string author;
    int year;
    bool available;
};

// Складений ключ для пошуку унікальних книг
struct BookKey
{
    std::string author;
    std::string title;
};

// Хеш-функція для складеного ключа
struct BookKeyHash
{
    std::size_t operator()(const BookKey &key) const
    {
        std::size_t h1 = std::hash<std::string>{}(key.author);
        std::size_t h2 = std::hash<std::string>{}(key.title);
        return h1 ^ (h2 << 1);
    }
};

// Предикат рівності для складеного ключа
struct BookKeyEqual
{
    bool operator()(const BookKey &a, const BookKey &b) const
    {
        return a.author == b.author && a.title == b.title;
    }
};

// Структура запиту на видачу книги для черги
struct CheckoutRequest
{
    int id;
    std::string readerName;
    int bookId;
};

#endif