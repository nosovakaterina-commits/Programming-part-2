#ifndef BOOK_CATALOG_HPP
#define BOOK_CATALOG_HPP

#include <string>
#include <vector>

struct Book
{
    int id;
    std::string title;
    std::string author;
    int year;
    bool available;
};

// Функтор зі станом для масштабування числових показників
class BookRatingScaler
{
private:
    double factor;

public:
    BookRatingScaler(double f) : factor(f) {}
    double operator()(int year) const
    {
        return year * factor; // Умовна трансформація року в індикатор
    }
};

// Прототип допоміжної функції для виведення даних
void printCatalog(const std::vector<Book> &catalog, const std::string &message);

#endif
