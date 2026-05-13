# Lab 03 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _10_05_26

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
├── CMakeLists.txt
|__ README.md
```

# Lab Instructions

 The
following requirements are mandatory for all variants:
1) the class must contain only fields of plain types;
2) the number of fields must be 4 or 5;
3) there must be at least one constructor;
4) all methods listed in the variant description must be implemented;
5) getters and setters for all internal fields must also be implemented;
6) a UML class diagram in PlantUML must be created;
7) a separate image file must be generated from the diagram;
8) a main() function must be written to create an object and demonstrate the
methods.

### How to Build
```bash
cd lab03 
cmake -S . -B build
cmake --build build
```

### How to

```bash
cd build
./app
```

### Report

The goal of this lab is to reinforce the basic concepts of object-oriented programming in C++, learn how to design a simple class, represent its interface in UML, and connect the diagram with a real implementation.

In this lab, I completed the following tasks:
Create the class describes one student in an academic group.
---

### Test Results

![alt text](result.png)

### Runtime Output

--- Student Data ---
ID: 5
Course: 1
Avarage Grade: 92.3
Absences: 45
Can receive scholarship: Yea

--- Change data ---
Added 6 absences. Total: 51
Updated grade to: 93.2

--- Final Student Data ---
New Cource: 2
Is exelent student? : Yea
 Can receive scholarship now? : No

### Diagram

![alt text](diagram.png)

### Conclusion

In this lab I reinforce the basic concepts of object-oriented programming in C++, learn how
to design a simple class, represent its interface in UML, and connect the diagram with a
real implementation.

In my version of the program, I wrote code that tells the program whether a student will receive a scholarship based on their grades and attendance.