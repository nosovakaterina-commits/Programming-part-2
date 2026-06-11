#include "BookCatalog.hpp"
#include <iostream>

// Функція для виведення каталогу
void printCatalog(const std::vector<Book>& catalog, const std::string& message) {
    std::cout << "=== " << message << " ===" << std::endl;
    for (const auto& b : catalog) {
        std::cout << "ID: " << b.id << " | Title: " << b.title 
                  << " | Author: " << b.author << " | Year: " << b.year 
                  << " | Available: " << (b.available ? "Yes" : "No") << std::endl;
    }
    std::cout << std::endl;
}