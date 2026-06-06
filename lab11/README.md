# Lab 11 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _04_06_26
---

## Task Discription

The implemented code snippet demonstrates the mechanism of automatic template argument deduction, allowing the compiler to independently determine the parameters of type T based on the int and double variable values passed to the maxValue and minValue functions without explicitly specifying them in angle brackets.

---

## Structure

```text
lab11/
├── assets/
    ├── uml/
        |__ diagram.puml
├── include/
    ├── grade_book.h
    ├── named_record.h
    |__ grade_threshold.h
├── tets/
    |__ test_grade_book.cpp
├── CMakeLists.txt
├── main.cpp
|__ README.md
```

# Lab Instructions

For the selected variant, the student must:
1. analyze the problem domain and identify the classes that should be represented as templates;
2. implement Part 1 and Part 2 of the assigned variant in one coherent project;
3. use at least one class template with a type parameter and at least one non-type parameter where required by the variant;
4. use raw arrays wherever fixed-capacity storage is needed;
5. implement constructors, accessors, and behavior methods appropriate for the chosen domain;
6. provide meaningful validation of indices, capacities, and other boundary conditions;
7. create a demonstration program in main.cpp;
8. create unit tests for the key template classes and their special cases;
9. organize the project as a structured CMake-based directory;
10. include a short compiler-oriented investigation of instantiated types in the report.

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
./lab11_tests
./lab11_main
```
 
### Report

The goal of this lab is to practice the design and implementation of class templates in C++, including ordinary class templates, templates with multiple parameters, non-type template parameters, full or partial specialization, and the basic analysis of template instantiations produced by the compiler. The work is designed for an extended laboratory session of approximately four academic hours and is organized as a single assignment consisting of two parts.

In this lab, I completed the following tasks:
Part 1 – Core template class:
• Implement GradeBook<T, N> that stores up to N grades in a raw array.
• Provide operations such as addGrade(), get(), count(), best(), and average().
• Use the template with at least two numeric types, for example int and double.

Part 2 – Extension and specialization:
• Implement NamedRecord<NameType, ValueType> or another two-parameter helper class used in the grade-report domain.
• Add a helper template GradeThreshold<T> with a full specialization for double that provides named pass() and excellent() boundary constants (for example 60.0 and 90.0); the primary template serves integer grades.
• Compare two concrete instantiations of GradeBook<T, N> in the compileroriented investigation.

Template focus: class template with a non-type parameter, a second template class with two type parameters, and full specialization of a domain-policy helper for a concrete arithmetic type.

---

### Test Results

![alt text](tests.png)

### Runtime Output

![alt text](result.png)

--- Testing GradeBook<int, 5> ---
Grades count: 4 / 5
Best grade: 95
Average grade: 79.5
Excellent threshold (int): 90

--- Testing GradeBook<double, 4> ---
Grades count: 3 / 4
Best grade: 91
Average grade: 77.6667
Pass threshold (double): 60
Excellent threshold (double): 90

--- Testing NamedRecord<std::string, double> ---
Student: Kate Nosova, Grade: 95.5 (Excellent!)

### Diagram

![alt text](diagram.png)

### Conclusion  !


In this lab I learn how to develop a code fragment that demonstrates the operation of the automatic template argument inference mechanism, thanks to which the compiler independently determines parameters of type T based on the values ​​of the int and double variables passed to the maxValue and minValue functions without explicitly specifying them in angle brackets.

In my version of the program, I wrote code that implements a generic fixed-capacity grade book based on the GradeBook<T, N> class template, where data storage is organized via a raw array without utilizing the forbidden STL containers.