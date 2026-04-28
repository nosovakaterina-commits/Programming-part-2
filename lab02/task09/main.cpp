#include<iostream>
#include<string>
#include<format>

int main() {
    int number = 749;
    std::cout << std::format("Number: {}\n", number);
    std::cout << std::format("Decimal: {}\n", number);
    std::cout << std::format("Hexadecimal: {:#x}\n",number);
    std::cout << std::format("Octal: {:#o}\n", number);

    double pi = 3.14159;
    std::cout << std::format("Pi value: {:5.2f}\n", pi);

    return 0;
}