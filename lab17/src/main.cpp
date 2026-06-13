#include <iostream>
#include "catalog.h"

int main() {
    // Демонстраційний набір даних (20 книг за методичкою)
    std::vector<Book> initialBooks = {
        {1, "The Hobbit", "J.R.R. Tolkien", 1937, true},
        {2, "The Fellowship of the Ring", "J.R.R. Tolkien", 1954, true},
        {3, "The Two Towers", "J.R.R. Tolkien", 1954, false},
        {4, "The Return of the King", "J.R.R. Tolkien", 1955, true},
        {5, "1984", "George Orwell", 1949, true},
        {6, "Animal Farm", "George Orwell", 1945, true},
        {7, "Brave New World", "Aldous Huxley", 1932, false},
        {8, "Fahrenheit 451", "Ray Bradbury", 1953, true},
        {9, "The Great Gatsby", "F. Scott Fitzgerald", 1925, true},
        {10, "To Kill a Mockingbird", "Harper Lee", 1960, true},
        {11, "Moby Dick", "Herman Melville", 1851, false},
        {12, "Pride and Prejudice", "Jane Austen", 1813, true},
        {13, "Sense and Sensibility", "Jane Austen", 1811, true},
        {14, "Crime and Punishment", "Fyodor Dostoevsky", 1866, true},
        {15, "The Idiot", "Fyodor Dostoevsky", 1869, false},
        {16, "The Catcher in the Rye", "J.D. Salinger", 1951, true},
        {17, "One Hundred Years of Solitude", "Gabriel Garcia Marquez", 1967, true},
        {18, "The Old Man and the Sea", "Ernest Hemingway", 1952, true},
        {19, "For Whom the Bell Tolls", "Ernest Hemingway", 1940, false},
        {20, "The Shining", "Stephen King", 1977, true}
    };

    LibraryCatalog catalog(initialBooks);

    std::cout << "Library catalog initialized successfully.\n";
    std::cout << "Total books indexed: " << catalog.getCatalogSize() << '\n';
    std::cout << "Unique authors count: " << catalog.getUniqueAuthorsCount() << '\n';

    return 0;
}