#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

int main() {
    std::ofstream report("report.txt");

    if(!report.is_open()) {
        std::cerr << "File was not created!"<< std::endl;
        return 1;
    }

    report << std::setw(30) << "Report" << "\n";
    report << std::string(40, '-') << "\n";

    report << std::left << std::fixed << std::setprecision(2);
    report << std::setw(20) << "Tasks completed: " << 11 <<"\n";
    report << std::setw(20) << "Is all correct? - "<< std::boolalpha << true << "\n";
    report << std::string(40,'-') << "\n";

    report << std::setw(20) << "Conclusion: " << "All 11 tasks completed correctly!" << "\n";

    report.close();

    if (report.good() || !report.fail()) {
        std::cout << "File was created!" << std::endl;
    }
    return 0;

}