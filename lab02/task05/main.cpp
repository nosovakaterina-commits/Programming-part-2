#include<iostream>
#include<iomanip>

int main() {
    int number = 749;
    std::cout << "Number: " << number << "\n\n";
    std::cout << "Decimal: " << std::dec << number << "\n";
    std::cout << "Hexadecimal: " << std::hex << number << "\n";
    std::cout << "Octal: " << std::oct << number << "\n";

    return 0;
}