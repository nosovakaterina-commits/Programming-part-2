#include "TicketProcessor.h"
#include <iostream>

int main() {
    char buffer[100];
    std::snprintf(buffer, sizeof(buffer), "Initializing Ticket Processing System v%d.%d...", 1, 0);
    std::cout << buffer << std::endl;

    TicketProcessor processor;

    std::cout << "\n[STEP 1] Loading input data from file..." << std::endl;
    if (!processor.loadInputFile("data/input.txt")) {
        std::cerr << "Process terminated due to missing data file." << std::endl;
        return 1;
    }

    // Генеруємо та записуємо фінальний звіт
    std::cout << "\n[STEP 2] Generating final structured report..." << std::endl;
    if (processor.generateReport("data/expected_report.txt")) {
        std::cout << "[SUCCESS] Report successfully generated in data/expected_report.txt" << std::endl;
    } else {
        std::cerr << "[FAILURE] Failed to build the report file." << std::endl;
        return 1;
    }

    return 0;
}