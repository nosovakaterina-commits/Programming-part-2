#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <array>
#include <iomanip>
#include "BookCatalog.hpp"

int main() {
    // ГЕНЕРАЦІЯ ДАНИХ
    std::mt19937 engine{42}; // Генератор зі сталим сідом для відтворюваності
    std::uniform_int_distribution<int> yearDist{1990, 2025};
    std::uniform_int_distribution<int> availabilityDist{0, 1};
    
    std::array<std::string, 4> authors{"Martin", "Stroustrup", "Prata", "King"};
    std::uniform_int_distribution<int> authorIndexDist{0, 3};

    std::vector<Book> books(20); // Створення колекції на 20 елементів
    int currentId = 1;

    // Заповнення контейнера через std::generate з лямбдою
    std::generate(books.begin(), books.end(), [&]() {
        int id = currentId++;
        return Book{
            id,
            "Book Volume " + std::to_string(id),
            authors[authorIndexDist(engine)],
            yearDist(engine),
            availabilityDist(engine) == 1
        };
    });

    printCatalog(books, "Initial Book Catalog");

    // ПОШУК ТА ПІДРАХУНОК
    std::string targetAuthor = "Stroustrup";
    
    // Лямбда для пошуку
    auto isAvailableByAuthor = [targetAuthor](const Book& b) {
        return b.available && b.author == targetAuthor;
    };

    // Пошук першої доступної книги автора за допомогою std::find_if
    auto firstBookIt = std::find_if(books.begin(), books.end(), isAvailableByAuthor);
    if (firstBookIt != books.end()) {
        std::cout << "First available book by " << targetAuthor << ": " 
                  << firstBookIt->title << " (" << firstBookIt->year << ")\n" << std::endl;
    } else {
        std::cout << "No available books found by " << targetAuthor << "\n" << std::endl;
    }

    int targetYear = 2010;
    // Підрахунок книг, виданих після заданого року через std::count_if
    int countRecent = std::count_if(books.begin(), books.end(), [targetYear](const Book& b) {
        return b.year > targetYear;
    });
    std::cout << "Number of books published after " << targetYear << ": " << countRecent << std::endl;

    // Логічна перевірка за допомогою std::any_of
    bool hasOldBooks = std::any_of(books.begin(), books.end(), [](const Book& b) {
        return b.year < 2000;
    });
    std::cout << "Has books older than year 2000: " << (hasOldBooks ? "Yes" : "No") << "\n" << std::endl;

    // СОРТУВАННЯ ТА МІНІМУМИ/МАКСИМУМИ
    // Сортування за двома критеріями: спочатку за роком, потім за назвою
    std::stable_sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        if (a.year != b.year) {
            return a.year < b.year; // Сортування за роком
        }
        return a.title < b.title; // Сортування за назвою при рівності років
    });

    printCatalog(books, "Sorted Catalog (by Year and Title)");

    // Пошук найстарішої та найновішої книги через std::minmax_element
    auto minMaxBooks = std::minmax_element(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.year < b.year;
    });
    std::cout << "Oldest book year: " << minMaxBooks.first->year << std::endl;
    std::cout << "Newest book year: " << minMaxBooks.second->year << "\n" << std::endl;

    // АГРЕГАЦІЯ ТА ЦИФРОВА ОБРОБКА
    double totalYears = std::accumulate(books.begin(), books.end(), 0.0, [](double sum, const Book& b) {
        return sum + b.year;
    });
    std::cout << "Average publication year: " << std::fixed << std::setprecision(1) 
              << (totalYears / books.size()) << "\n" << std::endl;

    // Використання std::transform та мого функтора зі станом
    std::vector<double> scaledIndicators(books.size());
    BookRatingScaler scaler(0.005);
    
    std::transform(books.begin(), books.end(), scaledIndicators.begin(), [&](const Book& b) {
        return scaler(b.year);
    });
    std::cout << "First scaled indicator: " << scaledIndicators[0] << "\n" << std::endl;

    // ВИЛУЧЕННЯ ЕЛЕМЕНТІВ
    // Класичний підхід через std::remove_if та метод .erase()
    books.erase(
        std::remove_if(books.begin(), books.end(), [](const Book& b) {
            return !b.available; // Вилучаємо недоступні книги
        }),
        books.end()
    );

    printCatalog(books, "Catalog After Removing Unavailable Books");

    return 0;
}