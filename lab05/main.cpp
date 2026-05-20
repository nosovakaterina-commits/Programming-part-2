#include <iostream>
#include "University.hpp" 
#include "Student.hpp"

static void printUniversitySummary(const University& university) {
    std::cout << "University: \"" << university.getName() << "\"\n";
    std::cout << "Departments count: " << university.getDepartmentCount() << "\n\n";

    for (int i = 0; i < university.getDepartmentCount(); ++i) {
        const Department* department = university.getDepartmentAt(i);
        if (department == nullptr) {
            continue;
        }

        std::cout << "Department: \"" << department->getName() << "\"\n";
        std::cout << "Professors count: " << department->getProfessorCount() << '\n';
        std::cout << "Courses count: " << department->getCourseCount() << "\n\n";

        for (int j = 0; j < department->getCourseCount(); ++j) {
            const Course* course = department->getCourseAt(j);
            if (course == nullptr) {
                continue;
            }

            std::cout << "Course: \"" << course->getTitle() << "\"\n";
            std::cout << "Students count: " << course->getStudentCount() << '\n';

            for (int k = 0; k < course->getStudentCount(); ++k) {
                const Student* student = course->getStudentAt(k);
                if (student != nullptr) {
                    std::cout << "  - [" << student->getId() << "] \"" 
                              << student->getName() << "\", course: " 
                              << student->getCourse() << ", grade: " 
                              << student->getAverageGrade() << '\n';
                }
            }
            std::cout << '\n';
        }
    }
}

int main() {
    University university("National Technological University");

    Professor professor1("Dr. Alexander Ivanov", 45000.0, "Advanced C++");
    Professor professor2("Dr. Maria Petrova", 48000.0, "Discrete Mathematics");

    Department department1("Computer Science");

    Course course1("Advanced C++");
    Course course2("Discrete Mathematics");

    Student student1("Katerina Nosova", 101, 2, 95.5, true, 2);
    Student student2("Alex Smith", 102, 2, 78.0, false, 12);

    department1.addProfessor(professor1);
    department1.addProfessor(professor2);

    university.addDepartment(department1);
    
    department1.addCourse(course1);
    department1.addCourse(course2);

    course1.addStudent(student1);
    course1.addStudent(student2);

    std::cout << "Student " << student1.getName() << " entered the university.\n\n";

    printUniversitySummary(university);

    course1.removeStudent(102); 

    std::cout << "After removing one student from Course \"Advanced C++\":\n\n";
    printUniversitySummary(university);

    std::cout << "Student \"" << student2.getName() 
              << "\" still exists independently:\n";
    std::cout << "  -> can receive scholarship: " 
              << (student2.canReceiveScholarship() ? "yes" : "no") << "\n";

    return 0;
}
