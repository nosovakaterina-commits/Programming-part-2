# Lab 09 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _3_06_26

---
# Task Description

Multiple inheritance and the diamond problem in C++.

---

## Structure

```text
lab09/
├── assets/
├── task_1/
    ├── private/
        ├── Device.cpp
        ├── InputDevice.cpp
        ├── OutpuDevice.cpp
        |__ TouchDisplay.cpp
    ├── public/
        ├── Device.hpp
        ├── InputDevice.hpp
        ├── OutputDevice.hpp
        |__ TouchDisplay.hpp
    ├── uml/
        |__ diagram.puml
    ├── tets/
        |__ test_task_1.cpp
    ├── CMakeLists.txt
    |__ main.cpp
├── task_2/
    ├── private/
        ├── Student.cpp
        ├── Athlete.cpp
        |__ CollegeAthlete.cpp
    ├── public/
        ├── Student.hpp
        ├── Athlete.hpp
        |__ CollegeAthlete.hpp
    ├── uml/
        |__ diagram.puml
    ├── tets/
        |__ test_task_2.cpp
    ├── CMakeLists.txt
    |__ main.cpp
├── CMakeLists.txt
|__ README.md
```

# Lab Instructions

Task 1

1) Analyze the diamond inheritance hierarchy assigned by the variant (Table 1).
2) Draw a UML diagram of the incorrect (non-virtual) version, clearly showing the duplicated base subobject.
3) Implement the incorrect version and demonstrate the compilation or runtime error that arises when calling the ambiguous function.
4) Refactor the intermediate classes to use virtual inheritance.
5) Adjust the most-derived class constructor to directly initialize the virtual base.
6) Draw a UML diagram of the corrected version, showing the single shared base subobject.
7) Implement the corrected version and demonstrate that the ambiguity is gone.
8) In the report, explain why the virtual base must be constructed in the mostderived class and what changes in the object memory layout as  a result.

Task 2

1) Implement the multiple inheritance hierarchy assigned by the variant (Section 3).
2) Each base class must have at least one virtual method and a virtual destructor.
3) Each derived class must implement the required virtual interface and add meaningful domain-specific state and behavior.
4) Use virtual inheritance where the hierarchy contains a shared base to avoid the diamond problem.
5) Constructors must correctly initialize all base parts through initializer lists.
6) All overriding methods must be marked with override.
7) In main(), create objects of different classes and store them in a plain array of base-class pointers.
8) Demonstrate polymorphism by calling the same virtual method for all array elements in a loop.
9) Draw a UML diagram that shows the complete class hierarchy for the selected variant.

### How to Build
```bash
cd lab03 
cmake -S . -B build
cmake --build build
```

### How to

```bash
cd build
./task_1/task1_exe
./task_1/task1_tests
./task_2/task2_exe
./task_2/task2_tests
```
 
### Report  

The goal of this lab is to acquire practical skills in designing class hierarchies that involve multiple inheritance in C++, understanding the causes and consequences of the diamond inheritance problem, applying virtual inheritance as the standard solution, correctly ordering constructor calls with virtual base classes, and implementing domain models that combine capabilities from independent class branches.

In this lab, I completed the following tasks:
task 1:
Resolving the Diamond Inheritance Problem
Device InputDevice, OutputDevice TouchDisplay void describe() — prints device info

task 2:
Multiple Inheritance Hierarchy
Person Student, Athlete CollegeAthlete A person who studies and competes in sports.

---

### Test Results

![alt text](test.png)

### Runtime Output

![alt text](result.png)
task 1:
Device Name: ASUS ProArt Screen | Current Power: OFF
 -> Input Feature: Scanning at 144 Hz.
 -> Output Feature: Displaying at 3840x2160 resolution.

[POWER] Device 'ASUS ProArt Screen' is now ON.

task 2:
College Athlete Profile: Kate Nosova
University: NTU KhPI
 -> Academic status: Studying Computer Science with a current GPA of 4.9.
 -> Athletic status: Training hard in Volleyball for 14 hours a week.

### Diagram

task 1:
![alt text](diagram_task_1.png)

task 2:
![alt text](diagram_task_2.png)

### Conclusion

In this lab I learn how to acquire practical skills in designing class hierarchies that involve multiple inheritance in C++, understanding the causes and consequences of the diamond inheritance problem, applying virtual inheritance as the standard solution, correctly ordering constructor calls with virtual base classes, and implementing domain models that combine capabilities from independent class branches.

In my version of the program, I wrote code that implemented virtual inheritance for device classes (Device, InputDevice, OutputDevice, TouchDisplay), which allowed the base class data to be duplicated in memory and avoided the ambiguity problem. And created a multiple inheritance system for the Student and Athlete entities in the derived class CollegeAthlete, initializing the object with its real data.