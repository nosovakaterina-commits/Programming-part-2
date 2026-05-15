# Lab 04 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _15_05_26

---
# Task Description

The class describes one student in an academic group.

---

## Structure

```text
lab03/
├── assets/
├── include/
    |__ Student.hpp
├── src/
    ├── Student.cpp
    |__ main.cpp
├── uml/
    |__ diagram.puml
├── tets/
    ├── test_Student.cpp
    |__ test_main.cpp
├── CMakeLists.txt
|__ README.md
```

# Lab Instructions

 The following requirements are mandatory for all variants:
1) the class and the field set must fully match the specification of laboratory work No. 3;
2) the class must be organized as a library;
3) a separate demonstration main() must be kept;
4) a test main() for running unit tests must be added;
5) a set of unit tests must be written for at least the constructor, getters/setters, and 3–4 meaningful methods;
6) a UML class diagram must be added;
7) the commands for building, running the application, and running the tests must be shown.

### How to Build
```bash
cd lab03 
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

### How to

```bash
cd build
./student_app
```

### Report

The goal of this lab is to learn to treat testing as an integral part of development, extract a class into a library, and create a set of unit tests for it.

In this lab, I completed the following tasks:
Create the class describes one student in an academic group.
---

### Test Results

![alt text](tests.png)

 Start 1: StudentConstructorTest.StoresPositiveValues
1/5 Test #1: StudentConstructorTest.StoresPositiveValues ..........   Passed    0.01 sec
    Start 2: StudentConstructorTest.ReplacesInvalidValue
2/5 Test #2: StudentConstructorTest.ReplacesInvalidValue ..........   Passed    0.00 sec
    Start 3: StudentStateTest.PromoteToNextChangeState
3/5 Test #3: StudentStateTest.PromoteToNextChangeState ............   Passed    0.00 sec
    Start 4: StudentMathTest.CalculatesScholarshipAndExcellence
4/5 Test #4: StudentMathTest.CalculatesScholarshipAndExcellence ...   Passed    0.00 sec
    Start 5: StudentAbsencesTest.IncrementsAbsencesCorrectly
5/5 Test #5: StudentAbsencesTest.IncrementsAbsencesCorrectly ......   Passed    0.00 sec

100% tests passed, 0 tests failed out of 5

Total Test time (real) =   0.03 sec

### Runtime Output

--- Student Data ---
ID: 5
Course: 1
Avarage Grade: 92.3
Absences: 15
Can receive scholarship: Yes

--- Change data ---
Added 6 absences. Total: 21
Updated grade to: 93.2

--- Final Student Data ---
New Cource: 2
Is exellent student? : Yes
 Can receive scholarship now? : Yes

### Diagram

![alt text](diagram.png)

### Conclusion

In this lab I learn how to treat testing as an integral part of development, extract a class into a library, and create a set of unit tests for it.

In my version of the program, I wrote code that tells the program whether a student will receive a scholarship based on their grades and attendance. All tests that I write is passed.
