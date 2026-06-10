#include "Ticket.h"
#include "StringUtils.h"
#include <regex>
#include <charconv>

bool isValidEmail(const std::string& email) {
    // Шаблон регулярного виразу для перевірки email 
    const std::regex email_pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, email_pattern);
}

bool validateTicket(const Ticket& ticket, std::string& out_error_reason) {
    if (ticket.id <= 0) {
        out_error_reason = "Invalid or missing Ticket ID";
        return false;
    }
    if (ticket.user.empty()) {
        out_error_reason = "User field is empty";
        return false;
    }
    if (ticket.priority != "low" && ticket.priority != "medium" && ticket.priority != "high") {
        out_error_reason = "Invalid priority level (must be: low, medium, high)";
        return false;
    }
    if (ticket.response_time < 0) {
        out_error_reason = "Response time cannot be negative";
        return false;
    }
    if (ticket.status != "open" && ticket.status != "closed") {
        out_error_reason = "Invalid status (must be: open, closed)";
        return false;
    }
    if (!isValidEmail(ticket.email)) {
        out_error_reason = "Invalid email syntax";
        return false;
    }
    return true;
}

Ticket parseTicketLine(std::string_view line, bool& out_success, std::string& out_error) {
    Ticket t;
    out_success = true;

    // Розбиваємо рядок за символом крапки з комою ';'
    auto pairs = StringUtils::split_view(line, ';');
    for (auto const& pair : pairs) {
        auto trimmed_pair = StringUtils::trim_view(pair);
        if (trimmed_pair.empty()) continue;

        // Розбиваємо кожну пару на "ключ" і "значення" через '='
        auto kv = StringUtils::split_view(trimmed_pair, '=');
        if (kv.size() != 2) {
            out_success = false;
            out_error = "Invalid key-value format in token";
            return t;
        }

        auto key = StringUtils::trim_view(kv[0]);
        auto value = StringUtils::trim_view(kv[1]);

        if (key == "ticket") {
            // Конвертуємо string_view в int за допомогою std::from_chars (C++17)
            std::from_chars(value.data(), value.data() + value.size(), t.id);
        } else if (key == "user") {
            t.user = std::string(value);
        } else if (key == "priority") {
            t.priority = std::string(value);
        } else if (key == "response") {
            std::string temp(value);
            try {
                t.response_time = std::stod(temp);
            } catch (...) {
                t.response_time = -1.0;
            }
        } else if (key == "status") {
            t.status = std::string(value);
        } else if (key == "email") {
            t.email = std::string(value);
        }
    }
    return t;
}