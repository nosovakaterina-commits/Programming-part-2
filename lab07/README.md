# Lab 03 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _25_05_26

---
# Task Description

Building class hierarchies in C++ based on inheritance.

---

## Structure

```text
lab03/
├── assets/
    ├── uml/
        |__ diagram.puml
├── main.cpp
├── public/
    ├── Vehicles.hpp
    ├── Truch.hpp
    ├── RefrigeratedTruck.hpp
    |__ PassengerCar.hpp
├── preivate/
    ├── Vehicles.cpp
    ├── Truch.cpp
    ├── RefrigeratedTruck.cpp
    |__ PassengerCar.cpp
├── CMakeLists.txt
|__ README.md
```

# Lab Instructions

1) Each class must be placed in its own pair of .h/.cpp files or an equivalent structure.
2) All public methods must be reflected in the UML diagram.
3) Each class must contain at least 2–3 fields of its own or a meaningful combination of several fields and new methods.
4) The implementation must include constructors with correct initializer lists.
5) If a derived-class method overrides a base-class method, this must be explicitly indicated with override.
6) At least one deliberate example of final, =default, or =delete must be shown where it is genuinely justified by the model.
7) In main(), objects from several hierarchy levels must be created, and the basic scenarios of their operation must be demonstrated.
8) The sizeof values for the base, intermediate, and deepest derived types must be printed separately, and the result must be briefly commented on.
9) The code must compile as a complete C++ project with a clear directory structure.

### How to Build
```bash
cd lab03 
cmake -S . -B build
cmake --build build
```

### How to

```bash
cd build
./run_tests
./lab07
```

### Report

The goal of this lab is to acquire practical skills in constructing semantically correct class hierarchies in
C++, implementing multilevel inheritance without abstract classes and multiple inheritance, using initializer lists, override, final, =default, and =delete, and analyzing
how inherited and newly introduced state form a single object.

In this lab, I completed the following tasks:
 Vehicles: Vehicle -> Truck -> RefrigeratedTruck, with a separate PassengerCar branch.
---

### Test Results

![alt text](result.png)

### Runtime Output

RefrigeratedTruck Volvo FH (540 HP, 8.5 t), max load: 20 t, axles: 3, total transported: 15 t, temp: -18.5 C, cooling: yes
PassengerCar Toyota Camry (180 HP, 1.6 t), seats: 5, body: Sedan, trips: 1

sizeof(Vehicle) = 56
sizeof(Truck) = 72
sizeof(RefrigeratedTruck) = 88
sizeof(PassengerCar) = 104

### Diagram

![alt text](diagram.png)

### Conclusion

In this lab, I reinforced my practical skills in building clean and semantically correct class hierarchies in C++. I successfully implemented multi-level inheritance involving a base Vehicle class, an intermediate Truck branch leading to RefrigeratedTruck, and a standalone PassengerCar class, without messy multiple inheritance.

Through this assignment, I practiced using essential modern C++ tools:
Initializer lists in constructors for proper object setup.
override and final keywords to explicitly control method overriding and prevent unintended inheritance behavior.
=default and =delete to explicitly manage compiler-generated functions where logically justified.

A key part of the lab was analyzing the sizeof results for each class. The step-by-step increase from 56 bytes for the base Vehicle up to 88 and 104 bytes for the deepest derived types clearly demonstrates how C++ allocates memory sequentially, combining inherited states with newly introduced fields. Finally, I successfully mapped this entire structure into a clean UML diagram and organized the project using CMake.