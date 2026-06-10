#include <gtest/gtest.h>
#include "StringUtils.h"
#include "Ticket.h"

// Тест 1: Перевірка роботи Zero-Copy функції видалення пробілів
TEST(StringUtilsTest, TrimFunctionality) {
    std::string_view raw = "   ticket=102   ";
    std::string_view trimmed = StringUtils::trim_view(raw);
    EXPECT_EQ(trimmed, "ticket=102");
}

// Тест 2: Перевірка розбиття рядка за символом розділювача
TEST(StringUtilsTest, SplitFunctionality) {
    std::string_view raw = "key=value";
    auto parts = StringUtils::split_view(raw, '=');
    ASSERT_EQ(parts.size(), 2);
    EXPECT_EQ(parts[0], "key");
    EXPECT_EQ(parts[1], "value");
}

// Тест 3: Перевірка регулярного виразу для валідації пошти
TEST(TicketValidationTest, EmailRegexChecking) {
    EXPECT_TRUE(isValidEmail("kate@khpi.edu.ua"));
    EXPECT_FALSE(isValidEmail("corrupted_email.com"));
    EXPECT_FALSE(isValidEmail("user@domain"));
}

// Тест 4: Перевірка парсингу та повної валідації полів структури Ticket
TEST(TicketValidationTest, ParsingAndValidation) {
    std::string_view line = "ticket=501; user=John; priority=high; response=1.5; status=open; email=john@test.com";
    bool success = false;
    std::string error;
    
    Ticket t = parseTicketLine(line, success, error);
    ASSERT_TRUE(success);
    
    bool valid = validateTicket(t, error);
    EXPECT_TRUE(valid);
    EXPECT_EQ(t.id, 501);
    EXPECT_EQ(t.user, "John");
}