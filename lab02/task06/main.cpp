#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

int main() {
    std::ofstream outFile("table.txt");
    if(!outFile.is_open()) {
        std::cerr << "Error: File cannot be opened !" << std::endl;
        return 1;
    }
    outFile << std::left << std::setw(5) <<"№";
    outFile << std::setw(15) << "City";
    outFile << std::setw(10) << "Weather";
    outFile << std::setw(10) << "Degree" << "\n";

    outFile << std::string(40, '-') << "\n";

    outFile << std::left << std::setw(5) << 1;
    outFile << std::setw(15) << "Kyiv";
    outFile << std::setw(10) << "rain";
    outFile << std::setw(10) << "6.4°C" << "\n";

    outFile << std::left << std::setw(5) << 2;
    outFile << std::setw(15) << "Zaporozhye";
    outFile << std::setw(10) << "wind";
    outFile << std::setw(10) << "6.5°C" << "\n";

    outFile << std::left << std::setw(5) << 4;
    outFile << std::setw(15) << "Odessa";
    outFile << std::setw(10) << "hail";
    outFile << std::setw(10) << "6.0°C" << "\n";

    outFile << std::left << std::setw(5) << 5;
    outFile << std::setw(15) << "Dnipro";
    outFile << std::setw(10) << "rain";
    outFile << std::setw(10) << "6.7°C" << "\n";

    outFile.close();

    std::cout <<"Table has been written to table.txt successfully!" << std::endl;
    
    return 0;
}