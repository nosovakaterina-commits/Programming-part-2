#include "StringUtils.h"

namespace StringUtils {
    std::string_view trim_view(std::string_view str) {
        const std::string_view whitespace = " \t\r\n";
        // Шукаємо перший символ, який не є пробілом
        const auto start = str.find_first_not_of(whitespace);
        if (start == std::string_view::npos) {
            return {}; // Якщо рядок порожній або містить лише пробіли
        }
        // Шукаємо останній символ, який не є пробілом
        const auto end = str.find_last_not_of(whitespace);
        return str.substr(start, end - start + 1);
    }

    std::vector<std::string_view> split_view(std::string_view str, char delimiter) {
        std::vector<std::string_view> result;
        size_t start = 0;
        size_t end = str.find(delimiter);

        // Проходимо по всьому рядку та виділяємо блоки між розділювачами
        while (end != std::string_view::npos) {
            result.push_back(str.substr(start, end - start));
            start = end + 1;
            end = str.find(delimiter, start);
        }
        // Додаємо останній залишок рядка
        result.push_back(str.substr(start));
        return result;
    }
}