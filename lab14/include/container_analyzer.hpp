#ifndef CONTAINER_ANALYZER_HPP
#define CONTAINER_ANALYZER_HPP

#include "record.hpp"
#include <vector>
#include <deque>
#include <list>

class ContainerAnalyzer {
public:
    // Аналіз зміни ємності (capacity) вектора
    static void profileVectorCapacity();

    // Операції з 3 контейнерами (вставка в середину, видалення, обхід)
    static void demonstrateSequenceContainers();

    // Обробка даних без використання <algorithm>
    static const Record* findFirstByDestination(const std::vector<Record>& vec, const std::string& dest);
    static int countTicketsAbovePrice(const std::vector<Record>& vec, double minPrice);
    static double calculateTotalRevenue(const std::vector<Record>& vec);
    
    // Створення нової послідовності за критеріями оцінювання
    static std::vector<Record> filterByDestination(const std::vector<Record>& vec, const std::string& dest);

    // Порівняльний аналіз швидкості операцій
    static void runBenchmark();
};

#endif