#include<iostream>
#include<string>
#include<iomanip>

int main() {
    std::cout << std::left <<std::setw(5) << "ID";
    std::cout << std::setw(15) << "Date";
    std::cout << std::setw(10) << "Morning";
    std::cout << std::setw(10) << "Evening" << "\n";

    std::cout << std::string(40, '-') << "\n";

    std::cout << std::fixed << std::setprecision(1);

    std::cout << std::left << std::setw(5) << 1;
    std::cout << std::setw(15) << "21.04.26";
    std::cout << std::setw(10) << "5.9°C";
    std::cout << std::setw(10) << "5.2°C" << "\n";

    std::cout << std::left << std::setw(5) << 2;
    std::cout << std::setw(15) << "22.04.26";
    std::cout << std::setw(10) << "6.4°C";
    std::cout << std::setw(10) << "4.2°C" << "\n";

    std::cout << std::left << std::setw(5) << 3;
    std::cout << std::setw(15) << "23.04.26";
    std::cout << std::setw(10) << "7.1°C";
    std::cout << std::setw(10) << "6.8°C" << "\n";

    std::cout << std::left << std::setw(5) << 4;
    std::cout << std::setw(15) << "24.04.26";
    std::cout << std::setw(10) << "8.2°C";
    std::cout << std::setw(10) << "7.9°C" << "\n";

    std::cout << std::left << std::setw(5) << 5;
    std::cout << std::setw(15) << "25.04.26";
    std::cout << std::setw(10) << "9.3°C";
    std::cout << std::setw(10) << "8.5°C" << "\n";

    return 0;
}
