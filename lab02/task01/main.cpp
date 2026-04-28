#include<iostream>
#include<string>

int main() {
    std::string name = "Katerina";
    std::string group = "KH-925e";
    int number = 18;
    double decimal = 4.75;
    bool isStudent = true; 

    std::cout << " Informatoin " << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Group: " << group << "\n";
    std::cout << "Age: " << number << "\n";
    std::cout << "Average score: " << decimal << "\n";
    std::cout << "Is Student: " << std::boolalpha << isStudent << "\n";

    return 0;
}