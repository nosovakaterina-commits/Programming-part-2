#include "TicketProcessor.h"
#include "StringUtils.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <regex>

std::string TicketProcessor::maskEmail(const std::string& email) {
    std::regex email_regex(R"(^([^@])([^@]*)([^@])@(.+)$)");
    std::smatch match;

    if (std::regex_match(email, match, email_regex)) {
        std::string first_char = match[1].str();
        std::string middle = match[2].str();
        std::string last_char = match[3].str();
        std::string domain = match[4].str();

        // Замінюємо символи всередині локальної частини на зірочки '*'
        std::string stars(middle.length(), '*');
        if(stars.empty()) stars = "*"; // Якщо ім'я дуже коротке

        return first_char + stars + last_char + "@" + domain;
    }
    return email;
}

bool TicketProcessor::loadInputFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "[ERROR] Could not open input file: " << filepath << std::endl;
        return false;
    }

    std::string line;
    total_processed_lines = 0;
    corrupted_lines = 0;
    valid_tickets.clear();

    while (std::getline(file, line)) {
        total_processed_lines++;
        std::string_view view(line);
        view = StringUtils::trim_view(view);

        if (view.empty()) continue;

        bool parse_success = false;
        std::string error_msg;
        Ticket ticket = parseTicketLine(view, parse_success, error_msg);

        if (parse_success && validateTicket(ticket, error_msg)) {
            valid_tickets.push_back(ticket);
        } else {
            corrupted_lines++;
            std::cout << "[DIAGNOSTIC - LINE " << total_processed_lines << "] " 
                      << "Reason: " << error_msg << " | Raw data: " << line << std::endl;
        }
    }
    return true;
}

bool TicketProcessor::generateReport(const std::string& output_filepath) {
    std::ofstream out(output_filepath);
    if (!out.is_open()) {
        std::cerr << "[ERROR] Could not open report file for writing: " << output_filepath << std::endl;
        return false;
    }

    int open_count = 0;
    int closed_count = 0;
    double total_response_time = 0.0;

    for (const auto& t : valid_tickets) {
        if (t.status == "open") open_count++;
        else if (t.status == "closed") closed_count++;
        total_response_time += t.response_time;
    }

    double average_response = valid_tickets.empty() ? 0.0 : total_response_time / valid_tickets.size();

    // Запис красивої шапки та зведеної статистики (вирівнювання через маніпулятори)
    out << "=========================================================================\n";
    out << "                       SUPPORT TICKETS SUMMARY REPORT                    \n";
    out << "=========================================================================\n";
    out << " Total Processed Lines: " << total_processed_lines << "\n";
    out << " Valid Records Saved:   " << valid_tickets.size() << "\n";
    out << " Corrupted Records:     " << corrupted_lines << "\n";
    out << " Active (Open) Tickets: " << open_count << "\n";
    out << " Resolved (Closed):     " << closed_count << "\n";
    out << " Average Response Time: " << std::fixed << std::setprecision(2) << average_response << " hours\n";
    out << "=========================================================================\n\n";

    // Таблична частина звіту
    out << std::left << std::setw(8)  << "ID" 
                     << std::setw(12) << "USER" 
                     << std::setw(10) << "PRIORITY" 
                     << std::setw(10) << "RESPONSE" 
                     << std::setw(10) << "STATUS" 
                     << "MASKED EMAIL\n";
    out << "-------------------------------------------------------------------------\n";

    for (const auto& t : valid_tickets) {
        out << std::left << std::setw(8)  << t.id 
                         << std::setw(12) << t.user 
                         << std::setw(10) << t.priority 
                         << std::setw(10) << std::fixed << std::setprecision(1) << t.response_time 
                         << std::setw(10) << t.status 
                         << maskEmail(t.email) << "\n";
    }
    out << "-------------------------------------------------------------------------\n";

    return true;
}