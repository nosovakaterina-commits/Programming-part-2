#include <iostream>
#include <string>
#include "grade_book.h"
#include "named_record.h"
#include "grade_threshold.h"

int main() {
    // 1. Демонстрація GradeBook з цілими оцінками (int)
    std::cout << "--- Testing GradeBook<int, 5> ---" << std::endl;
    GradeBook<int, 5> intBook;
    intBook.addGrade(75);
    intBook.addGrade(95);
    intBook.addGrade(60);
    intBook.addGrade(88);

    std::cout << "Grades count: " << intBook.count() << " / " << intBook.capacity() << std::endl;
    std::cout << "Best grade: " << intBook.best() << std::endl;
    std::cout << "Average grade: " << intBook.average() << std::endl;
    std::cout << "Excellent threshold (int): " << GradeThreshold<int>::excellent() << std::endl << std::endl;

    // 2. Демонстрація GradeBook з дробовими оцінками (double)
    std::cout << "--- Testing GradeBook<double, 4> ---" << std::endl;
    GradeBook<double, 4> doubleBook;
    doubleBook.addGrade(82.5);
    doubleBook.addGrade(91.0);
    doubleBook.addGrade(59.5);

    std::cout << "Grades count: " << doubleBook.count() << " / " << doubleBook.capacity() << std::endl;
    std::cout << "Best grade: " << doubleBook.best() << std::endl;
    std::cout << "Average grade: " << doubleBook.average() << std::endl;
    std::cout << "Pass threshold (double): " << GradeThreshold<double>::pass() << std::endl;
    std::cout << "Excellent threshold (double): " << GradeThreshold<double>::excellent() << std::endl << std::endl;

    // 3. Демонстрація NamedRecord (двопараметричний шаблон)
    std::cout << "--- Testing NamedRecord<std::string, double> ---" << std::endl;
    NamedRecord<std::string, double> studentRecord("Kate Nosova", 95.5);
    std::cout << "Student: " << studentRecord.getName() << ", Grade: " << studentRecord.getValue() << " ";
    
    if (studentRecord.getValue() >= GradeThreshold<double>::excellent()) {
        std::cout << "(Excellent!)";
    } else if (studentRecord.getValue() >= GradeThreshold<double>::pass()) {
        std::cout << "(Passed)";
    } else {
        std::cout << "(Failed)";
    }
    std::cout << std::endl;

    return 0;
}