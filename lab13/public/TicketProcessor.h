#pragma once
#include "Ticket.h"
#include <string>
#include <vector>

class TicketProcessor {
private:
    std::vector<Ticket> valid_tickets;
    int total_processed_lines = 0;
    int corrupted_lines = 0;
    std::string maskEmail(const std::string& email);

public:
    bool loadInputFile(const std::string& filepath);
    bool generateReport(const std::string& output_filepath);

};