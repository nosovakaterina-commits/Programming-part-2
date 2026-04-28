#include<iostream>
#include<iomanip>

int main() {
    bool isTrue = true;
    bool isFalse = false;

    std::cout << "---Default numeric form ---" << "\n";
    std::cout << "Value 1: " << isTrue << "\n";
    std::cout << "Value 2: " << isFalse << "\n\n";
    
    std::cout << "---With std::boolalpha---" << "\n";
    std::cout << std::boolalpha;
    std::cout << "Value 1: " << isTrue << "\n";
    std::cout << "Value 2: " << isFalse << "\n";

    return 0;

}