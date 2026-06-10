#pragma once
#include <string>
#include <string_view>

struct Ticket {
    int id = 0;
    std::string user;
    std::string priority;
    double response_time = 0.0;
    std::string status;
    std::string email;
};

// Перевірка коректності формату Email за допомогою регулярного виразу
bool isValidEmail(const std::string& email);

// Повна валідація всіх полів тікета
bool validateTicket(const Ticket& ticket, std::string& out_error_reason);

// Функція для збирання структури Ticket із сирого рядка 
Ticket parseTicketLine(std::string_view line, bool& out_success, std::string& out_error);