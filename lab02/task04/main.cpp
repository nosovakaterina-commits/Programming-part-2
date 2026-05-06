#include<iostream>
#include<iomanip>

int main() {
    double number = 43.1522144;
    std::cout << "Default format: " << number << "\n\n";

    std::cout << std::fixed;
    std::cout << "Fixed notation: " << number << "\n";

    std::cout << std::scientific;
    std::cout << "Scientific notation: " << number <<"\n";

    std::cout << std::setprecision(2);
    std::cout << "Fixed notation with two digits after the decimal point: " << number <<"\n";

    std::cout << std::setprecision(5);
    std::cout << "Fixed notation with five digits after the decimal point: " << number <<"\n";

    return 0;
}