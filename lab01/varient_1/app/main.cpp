#include <iostream>
#include "math_utils.hpp"

int main() {
    std::cout << "4 + 8 = " << add(4, 8) <<std::endl;
    std::cout << "9 - 7 = " << sub(9, 7) <<std::endl;
    std::cout << "3 * 24 = " << mul(3, 24) <<std::endl;
    std::cout << "15 / 3 = " << divide(15, 3) <<std::endl;
    return 0;
}