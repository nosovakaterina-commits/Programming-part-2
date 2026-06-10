#pragma once
#include <string_view>
#include <vector>

namespace StringUtils {
    std::string_view trim_view(std::string_view str);

    std::vector<std::string_view> split_view(std::string_view str, char delimiter);
}