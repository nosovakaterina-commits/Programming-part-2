#include "book.hpp"
#include "simple_forward_list.hpp"
#include "simple_vector.hpp"

#include <iostream>
#include <algorithm>
#include <concepts>

// Перевірка відповідності кастомних ітераторів
static_assert(std::forward_iterator<SimpleForwardList<Book>::iterator>);
static_assert(std::forward_iterator<SimpleForwardList<Book>::const_iterator>);
static_assert(std::ranges::forward_range<SimpleForwardList<Book>>);

static_assert(std::contiguous_iterator<SimpleVector<Book>::iterator>);
static_assert(std::ranges::contiguous_range<SimpleVector<Book>>);

int main() {
    std::cout << "--- Testing SimpleForwardList (Node-based) ---\n";
    SimpleForwardList<Book> book_list;
    
    book_list.push_front({1, "The Hobbit", "J.R.R. Tolkien", 1937, true});
    book_list.push_front({2, "1984", "George Orwell", 1949, false});
    book_list.push_front({3, "Dune", "Frank Herbert", 1965, true});
    book_list.push_front({4, "Neuromancer", "William Gibson", 1984, false});

    // Пошук конкретної книги за допомогою STL алгоритму std::find_if
    auto list_found = std::find_if(book_list.begin(), book_list.end(), [](const Book& b) {
        return b.title == "1984";
    });
    if (list_found != book_list.end()) {
        std::cout << "Found by std::find_if: " << list_found->title << " (" << list_found->year << ")\n";
    }

    // Вставка книги всередину списку за допомогою insert_after
    if (list_found != book_list.end()) {
        book_list.insert_after(list_found, {5, "Foundation", "Isaac Asimov", 1951, true});
    }

    // Вибірка та вивід книг, що видані після 1950 року
    std::cout << "\nBooks published after 1950:\n";
    for (const auto& book : book_list) {
        if (book.year > 1950) {
            std::cout << " - " << book.title << " (" << book.year << ")\n";
        }
    }

    // Модифікація списку
    auto list_it = book_list.begin();
    if (list_it != book_list.end() && list_it->title == "Dune") {
        book_list.erase_after(list_it);
        std::cout << "\nErased the element after 'Dune'\n";
    }

    std::cout << "\n--- Testing SimpleVector (Contiguous) ---\n";
    SimpleVector<Book> book_vector;
    
    book_vector.push_back({1, "The Hobbit", "J.R.R. Tolkien", 1937, true});
    book_vector.push_back({2, "1984", "George Orwell", 1949, false});
    book_vector.push_back({3, "Dune", "Frank Herbert", 1965, true});
    book_vector.push_back({4, "Neuromancer", "William Gibson", 1984, false});

    // Підрахунок доступних книг за допомогою std::count_if
    auto available_count = std::count_if(book_vector.begin(), book_vector.end(), [](const Book& b) {
        return b.available;
    });
    std::cout << "Number of available books in vector: " << available_count << "\n";

    auto new_end = std::remove_if(book_vector.begin(), book_vector.end(), [](const Book& b) {
        return !b.available;
    });
    book_vector.resize(static_cast<std::size_t>(std::distance(book_vector.begin(), new_end)));

    // Виведення залишку книг після фільтрації
    std::cout << "\nVector contents after removing unavailable books:\n";
    for (const auto& book : book_vector) {
        std::cout << " - " << book.title << " [Available: " << std::boolalpha << book.available << "]\n";
    }

    return 0;
}