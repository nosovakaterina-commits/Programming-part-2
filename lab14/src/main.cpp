#include "container_analyzer.hpp"
#include <iostream>
#include <fstream>

int main() {
    std::cout << "--- Lab 14: Execution Started ---\n";
    ContainerAnalyzer::profileVectorCapacity();
    std::cout << "\n";

    std::vector<Record> records;
    records.emplace_back(1, "Alex", "Kyiv", 350.0);
    records.emplace_back(2, "Kate", "Lviv", 500.0);
    records.emplace_back(3, "John", "Kyiv", 120.0);

    const Record* match = ContainerAnalyzer::findFirstByDestination(records, "Kyiv");
    if (match) {
        std::cout << "Found passenger for Kyiv: " << match->passengerName << "\n";
    }

    int expensiveTickets = ContainerAnalyzer::countTicketsAbovePrice(records, 200.0);
    double totalRevenue = ContainerAnalyzer::calculateTotalRevenue(records);

    std::cout << "Tickets above 200: " << expensiveTickets << "\n";
    std::cout << "Total revenue: " << totalRevenue << "\n";

    std::ofstream outFile("data/expected_report.txt");
    if (outFile.is_open()) {
        if (match) {
            outFile << "First passenger found: " << match->passengerName << "\n";
        }
        outFile << "Tickets above 200: " << expensiveTickets << "\n";
        outFile << "Total revenue: " << totalRevenue << "\n";
        outFile.close();
    }

    std::vector<Record> filtered = ContainerAnalyzer::filterByDestination(records, "Kyiv");
    std::cout << "Filtered sequence size (Kyiv only): " << filtered.size() << "\n\n";

    std::cout << "--- Performance Benchmarking ---\n";
    ContainerAnalyzer::runBenchmark();

    return 0;
}