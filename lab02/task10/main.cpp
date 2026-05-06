#include<iostream>
#include<print>
#include<string>

int main() {
    int number = 5389;
    std::println("Number: {}", number);

    double val = 538.9;
    std::println("Scientific notation: {:.3f}", val);
    
    std::string name = "Katerina";
    std::println("User: {:>10}", name);

    return 0;
}