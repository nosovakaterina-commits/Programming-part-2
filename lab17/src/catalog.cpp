#include "catalog.h"
#include <stdexcept>

LibraryCatalog::LibraryCatalog(const std::vector<Book>& books) {
    frequencyByYear.reserve(books.size()); // Оптимізація хеш-таблиці
    for (const auto& book : books) {
        addBook(book);
    }
}

bool LibraryCatalog::addBook(const Book& book) {
    auto result = indexById.emplace(book.id, book);
    if (result.second) { // Оновлення інших індексів при успіху
        uniqueAuthors.insert(book.author);
        groupingByAuthor.emplace(book.author, book);
        ++frequencyByYear[book.year];
        return true;
    }
    return false;
}

bool LibraryCatalog::removeBook(int id) {
    auto it = indexById.find(id);
    if (it != indexById.end()) {
        Book removedBook = it->second;
        indexById.erase(it);
        
        if (--frequencyByYear[removedBook.year] == 0) {
            frequencyByYear.erase(removedBook.year);
        }
        
        auto range = groupingByAuthor.equal_range(removedBook.author);
        for (auto mit = range.first; mit != range.second; ++mit) {
            if (mit->second.id == id) {
                groupingByAuthor.erase(mit);
                break;
            }
        }
        
        if (!groupingByAuthor.contains(removedBook.author)) {
            uniqueAuthors.erase(removedBook.author);
        }
        return true;
    }
    return false;
}

const Book& LibraryCatalog::getBookById(int id) const {
    return indexById.at(id);
}

bool LibraryCatalog::hasBook(int id) const {
    return indexById.contains(id);
}

std::vector<Book> LibraryCatalog::getBooksByAuthor(const std::string& author) const {
    std::vector<Book> result;
    auto range = groupingByAuthor.equal_range(author);
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(it->second);
    }
    return result;
}

int LibraryCatalog::getBookCountByYear(int year) const {
    auto it = frequencyByYear.find(year);
    return (it != frequencyByYear.end()) ? it->second : 0;
}

size_t LibraryCatalog::getUniqueAuthorsCount() const {
    return uniqueAuthors.size();
}

size_t LibraryCatalog::getCatalogSize() const {
    return indexById.size();
}

void LibraryCatalog::addUniqueKey(const BookKey& key) {
    uniqueBookKeys.insert(key);
}

bool LibraryCatalog::hasUniqueKey(const BookKey& key) const {
    return uniqueBookKeys.contains(key);
}

void LibraryCatalog::pushRequest(const CheckoutRequest& request) {
    checkoutQueue.push(request);
}

CheckoutRequest LibraryCatalog::popRequest() {
    if (checkoutQueue.empty()) {
        throw std::runtime_error("Queue is empty");
    }
    CheckoutRequest front = checkoutQueue.front();
    checkoutQueue.pop();
    return front;
}

size_t LibraryCatalog::getQueueSize() const {
    return checkoutQueue.size();
}