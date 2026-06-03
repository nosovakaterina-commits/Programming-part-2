# Lab 05 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _15_05_26

---
# Task Description

Implement an object-oriented model of a university structure using aggregation.

---

## Structure

```text
lab05/
├── main.cpp
├── private/
    ├── University.cpp
    ├── Department.cpp
    ├── Professor.cpp
    ├── Course.cpp
    |__ Student.cpp
├── src/
    ├── University.hpp
    ├── Department.hpp
    ├── Professor.hpp
    ├── Course.hpp
    |__ Student.hpp
├── uml/
    |__ diagram.puml
├── tets/
    ├── test_University.cpp
    |__ test_main.cpp
├── CMakeLists.txt
|__ README.md
```

# Lab Instructions

 For each variant, the student must:
1. analyze the problem domain and identify the main entities;
2. design the required classes and their responsibilities;
3. establish aggregation relationships where appropriate;
4. implement each class in a separate source file;
5. draw a UML class diagram that shows classes, attributes, methods, associations, and multiplicities;
6. implement a demonstration program in main.cpp;
7. create unit tests for the key classes using a unit testing framework such as GoogleTest;
8. organize the project as a structured CMake-based directory;
9. follow consistent naming conventions and add concise meaningful comments where needed
### How to Build
```bash
cd lab03 
cmake -S . -B build
cmake --build build
```

### How to

```bash
ctest --test-dir build --output-on-failure
cd build
./university_tests
./university_app
```

### Report

The goal of this lab is to practice modeling class relationships in which one object contains or references other objects without taking full ownership of their lifetime. Students are expected to distinguish aggregation from composition, design a small domain model, represent it as a UML class diagram, and implement the corresponding C++ project.
---

### Test Results
![alt text](test.png)

Start 1: AllUniversityTests
1/1 Test #1: AllUniversityTests ...............   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec



./university_tests
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from UniversityTest
[ RUN      ] UniversityTest.StoresReferencesToIndependentObjects
[       OK ] UniversityTest.StoresReferencesToIndependentObjects (0 ms)
[ RUN      ] UniversityTest.CourseCanAddAndRemoveStudentsWithoutOwningTheirLifetime
[       OK ] UniversityTest.CourseCanAddAndRemoveStudentsWithoutOwningTheirLifetime (0 ms)
[ RUN      ] UniversityTest.DuplicateObjectsAreRejected
[       OK ] UniversityTest.DuplicateObjectsAreRejected (0 ms)
[----------] 3 tests from UniversityTest (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.

### Runtime Output

![alt text](result.png)

Student Katerina Nosova entered the university.

University: "National Technological University"
Departments count: 1

Department: "Computer Science"
Professors count: 2
Courses count: 2

Course: "Advanced C++"
Students count: 2
  - [101] "Katerina Nosova", course: 2, grade: 95.5
  - [102] "Alex Smith", course: 2, grade: 78

Course: "Discrete Mathematics"
Students count: 0

After removing one student from Course "Advanced C++":

University: "National Technological University"
Departments count: 1

Department: "Computer Science"
Professors count: 2
Courses count: 2

Course: "Advanced C++"
Students count: 1
  - [101] "Katerina Nosova", course: 2, grade: 95.5

Course: "Discrete Mathematics"
Students count: 0

Student "Alex Smith" still exists independently:
  -> can receive scholarship: yes

### Diagram

![alt text](diagram.png)

### Conclusion

In this lab I learn how to implement an object-oriented model of a university structure using aggregation.

In my version of the program, I wrote code that implements clean encapsulation with proper validation for every entity, ensuring that university data remains robust and completely identical to the instructor's architecture.
