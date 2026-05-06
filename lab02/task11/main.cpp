#include<iostream>
#include<iomanip>
#include<format>
#include<print>
#include<string>

int main() {
    std::string name = "Katerina";
    int age = 18;
    double score = 4.754;

    std::cout << "--- Version 1 (cout) ---" << std::endl;
    std::cout << "Name:" << std::setw(10) << name;
    std::cout << " | Age" << age;
    std::cout << " | Score: " << std::fixed << std::setprecision(2) << score;
    std::cout << std::endl << std::endl;

    std::cout << "--- Version 2 (format) ---" << std::endl;
    std::string formatted = std::format("Name: {:>10} | Age: {} | Score: {:.2f}\n", name, age, score);
    std::cout << formatted << std::endl;
    std::cout << "--- Version 3 (println-style) ---" << std::endl;
    std::cout << std::format("Name {:>10} | Age: {} | Score: {:.2f}\n", name, age, score);

    return 0;
}