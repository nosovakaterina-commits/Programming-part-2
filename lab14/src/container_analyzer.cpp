#include "container_analyzer.hpp"
#include <iostream>
#include <chrono>

void ContainerAnalyzer::profileVectorCapacity() {
    std::vector<Record> vec;
    size_t currentCapacity = vec.capacity();
    
    // Відстеження зміни capacity при динамічному додаванні
    for (int i = 0; i < 15; ++i) {
        vec.emplace_back(i, "Passenger", "Kyiv", 100.0);
        if (vec.capacity() != currentCapacity) {
            currentCapacity = vec.capacity();
            std::cout << "Vector growth -> Elements: " << vec.size() << ", Capacity: " << currentCapacity << "\n";
        }
    }
}

void ContainerAnalyzer::demonstrateSequenceContainers() {
    std::vector<Record> vec = { {1, "A", "Kyiv", 10.0}, {2, "B", "Lviv", 20.0} };
    std::deque<Record> deq = { {1, "A", "Kyiv", 10.0}, {2, "B", "Lviv", 20.0} };
    std::list<Record> lst = { {1, "A", "Kyiv", 10.0}, {2, "B", "Lviv", 20.0} };

    // Вставка в середину
    vec.insert(vec.begin() + 1, Record(99, "MidVec", "Odesa", 15.0));
    deq.insert(deq.begin() + 1, Record(99, "MidDeq", "Odesa", 15.0));
    
    auto listIt = lst.begin();
    std::advance(listIt, 1);
    lst.insert(listIt, Record(99, "MidList", "Odesa", 15.0));

    // Видалення елементів
    vec.erase(vec.end() - 1);
    deq.pop_front();
    lst.remove_if([](const Record& r) { return r.id == 2; });

    // Послідовний обхід
    for (const auto& r : vec) (void)r.id; 
    for (const auto& r : deq) (void)r.id;
    for (const auto& r : lst) (void)r.id;
}

// Пошук першого входження без <algorithm>
const Record* ContainerAnalyzer::findFirstByDestination(const std::vector<Record>& vec, const std::string& dest) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].destination == dest) {
            return &vec[i];
        }
    }
    return nullptr;
}

// Підрахунок елементів за критерієм без <algorithm>
int ContainerAnalyzer::countTicketsAbovePrice(const std::vector<Record>& vec, double minPrice) {
    int count = 0;
    for (const auto& record : vec) {
        if (record.ticketPrice > minPrice) {
            count++;
        }
    }
    return count;
}

// Акумуляція суми без <algorithm>
double ContainerAnalyzer::calculateTotalRevenue(const std::vector<Record>& vec) {
    double total = 0.0;
    for (const auto& record : vec) {
        total += record.ticketPrice;
    }
    return total;
}

// Створення нового контейнера без <algorithm>
std::vector<Record> ContainerAnalyzer::filterByDestination(const std::vector<Record>& vec, const std::string& dest) {
    std::vector<Record> result;
    for (const auto& record : vec) {
        if (record.destination == dest) {
            result.push_back(record);
        }
    }
    return result;
}

// Замір часу виконання операцій для звіту
void ContainerAnalyzer::runBenchmark() {
    const int iterations = 2000;

    auto s1 = std::chrono::high_resolution_clock::now();
    std::vector<Record> v;
    for(int i=0; i<iterations; ++i) v.push_back(Record(i, "N", "D", 50.0));
    auto e1 = std::chrono::high_resolution_clock::now();

    auto s2 = std::chrono::high_resolution_clock::now();
    std::deque<Record> d;
    for(int i=0; i<iterations; ++i) d.push_back(Record(i, "N", "D", 50.0));
    auto e2 = std::chrono::high_resolution_clock::now();

    auto s3 = std::chrono::high_resolution_clock::now();
    std::list<Record> l;
    for(int i=0; i<iterations; ++i) l.push_back(Record(i, "N", "D", 50.0));
    auto e3 = std::chrono::high_resolution_clock::now();

    std::cout << "Vector push_back: " << std::chrono::duration_cast<std::chrono::microseconds>(e1-s1).count() << " us\n";
    std::cout << "Deque push_back: " << std::chrono::duration_cast<std::chrono::microseconds>(e2-s2).count() << " us\n";
    std::cout << "List push_back: " << std::chrono::duration_cast<std::chrono::microseconds>(e3-s3).count() << " us\n";
}