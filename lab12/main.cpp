#include <iostream>
#include <memory>
#include "Student.h"
#include "Student_array.h"
#include "Simple_ptr.h"
#include "Smart_nodes.h"

// Кастомний делітер
void customStudentDeleter(Student* ptr) {
    std::cout << "[Custom Deleter] Freeing Student memory at address: " << ptr << std::endl;
    delete ptr; 
}

int main() {
    // Правило П'яти
    std::cout << "--- Student_array ---" << std::endl;
    Student_array myClass(2);
    myClass.at(0) = Student(1, "Katerina");
    myClass.at(1) = Student(2, "Alex");

    Student_array classCopy = myClass;
    std::cout << "Copied array size: " << classCopy.size() << " (Deep Copy Working)\n" << std::endl;

    std::cout << "--- std::unique_ptr & std::move ---" << std::endl;
    std::unique_ptr<Student> singleStudent = std::make_unique<Student>(10, "Ivan");
    
    std::unique_ptr<Student> movedStudent = std::move(singleStudent);
    std::cout << "Moved student name: " << movedStudent->getName() << std::endl;

    std::unique_ptr<Student[]> dynamicArray(new Student[2]{
        Student(11, "Olga"),
        Student(12, "Petro")
    });
    std::cout << "Unique array element 0: " << dynamicArray[0].getName() << "\n" << std::endl;

    std::cout << "--- Custom Deleter ---" << std::endl;
    {
        std::unique_ptr<Student, decltype(&customStudentDeleter)> customPtr(new Student(20, "Daria"), customStudentDeleter);
        std::cout << "Unique pointer with custom deleter created for: " << customPtr->getName() << std::endl;
    } 

    std::cout << "\n---  Cyclic References ---" << std::endl;
    
    std::cout << "1. Creating a cycle (Memory leak demonstration):" << std::endl;
    {
        auto st = std::make_shared<Student>(30, "Maxim");
        auto nodeA = std::make_shared<Smart_nodes>("Node_A (Leak Test)", st);
        auto nodeB = std::make_shared<Smart_nodes>("Node_B (Leak Test)", st);

        nodeA->next = nodeB;
        nodeB->next = nodeA; 
        std::cout << "  Cycle created between Node_A and Node_B. Leaving scope block..." << std::endl;
    }
    std::cout << "  (Notice: No node destructors were called above! Memory leaked!)\n" << std::endl;

    std::cout << "2. Breaking the cycle using std::weak_ptr:" << std::endl;
    {
        auto st = std::make_shared<Student>(31, "Elena");
        auto nodeA = std::make_shared<Smart_nodes>("Node_A (Safe Test)", st);
        auto nodeB = std::make_shared<Smart_nodes>("Node_B (Safe Test)", st);

        nodeA->next = nodeB; 
        nodeB->prev = nodeA; 
        std::cout << "  Safe structure created. Leaving scope block..." << std::endl;
    } 

    return 0;
}