#include<iostream>
#include<string>
#include<limits>

int main() {
    int age;
    double score;
    std::string firstName;
    std::string colour;

    std::cout <<"How old are you? -  ";
    std::cin >> age;

    std::cout <<"What is your average score? - ";
    std::cin >> score;

    std::cout <<"What is your name? - ";
    std::cin >> firstName;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout <<"What is your favourite colour? - ";
    std::cin >> colour;

    std::cout <<"\n--- Profile ---\n";
    std::cout <<"Name: " << firstName << "\n";
    std::cout <<"Age: " << age << "\n";
    std::cout <<"Average score: " << score << "\n";
    std::cout <<"favourite colour: " << colour << "\n";
    
    return 0;
}