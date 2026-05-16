#include <iostream>
#include <iomanip>
#include "Student.hpp"

int main() {
    Student student(5, 1, 92.3, true, 15);

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "--- Student Data ---" << std::endl;
    std::cout << "ID: " << student.getId() << std::endl;
    std::cout << "Course: " << student.getCourse() << std::endl;
    std::cout << "Avarage Grade: " << student.getAverageGrade() << std::endl;
    std::cout << "Absences: " << student.getAbsences() << std::endl;
    std::cout << "Can receive scholarship: " << (student.canReceiveScholarship() ? "Yes" : "No") << std::endl;

    std::cout << "\n--- Change data ---" << std::endl;

    student.addAbsence();
    student.addAbsence();
    student.addAbsence();
    student.addAbsence();
    student.addAbsence();
    student.addAbsence();
    std::cout << "Added 6 absences. Total: " << student.getAbsences() << std::endl;

    student.updateAverageGrade(93.2);
    std::cout << "Updated grade to: " << student.getAverageGrade() << std::endl;

    student.promoteToNextCourse();

    std::cout << "\n--- Final Student Data ---" << std::endl;
    std::cout << "New Cource: " << student.getCourse() << std::endl;
    std::cout << "Is exellent student? : " << (student.isExcellentStudent() ? "Yes" : "No") << std::endl;
    std::cout << " Can receive scholarship now? : " << (student.canReceiveScholarship() ? "Yes" : "No") << std::endl;

    return 0;
}