# Lab 08 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _26_05_26

---
# Task Description

Inheritance, abstract classes, and runtime polymorphism in C++.

---

## Structure


```text
lab08/
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
├──tests/
    |__ test_vehucles.cpp
├── CMakeLists.txt
|__ README.md
```


# Lab Instructions

1) In main(), create objects of different derived classes and store them in a plain array of base-class pointers.
2) Demonstrate runtime polymorphism by calling the same virtual method for all elements of that array in a loop.
3) Clarify the demo program in the report: explain why an array of base-class objects is not suitable and why a plain array of pointers preserves polymorphic behavior.
4) For one lower-level derived class, it is mandatory to inspect the active vtable in a debugger and briefly compare it with the base or intermediate class.
5) It is also mandatory to inspect the basic object memory layout: identify the object address, the first machine word that stores the hidden virtual-table pointer, and several subsequent machine words that belong to the object state.
6) Summarize which virtual functions are dispatched dynamically, which implementation is active for the selected lower-level object, and what can be seen in the first part of the memory layout.
 
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
./run_tests
./lab08
```

### Report

The goal of this lab is to acquire practical skills in constructing semantically correct class hierarchies in C++, introducing an abstract base class, implementing runtime polymorphism through virtual functions, using initializer lists and override, demonstrating dynamic dispatch through a plain array of base-class pointers, and performing a basic investigation of the virtual table of one lower-level derived class.


In this lab, I completed the following tasks:
Vehicles: Vehicle -> Truck -> RefrigeratedTruck, with a separate
PassengerCar branch.
---

### Test Results

![alt text](test1.png)
![alt text](test2.png)

### Runtime Output

![alt text](result.png)

=== Runtime Polymorphism Demonstration ===

Truck MAN TGX (440 HP, 7.5 t), max load: 15 t, axles: 2, total transported: 10 t
RefrigeratedTruck Volvo FH (540 HP, 8.5 t), max load: 20 t, axles: 3, total transported: 15 t, temp: -18.5 C, cooling: yes
PassengerCar Toyota Camry (180 HP, 1.6 t), seats: 5, body: Sedan, trips: 1

=== Memory Analysis (sizeof) ===

sizeof(void*)              = 8
sizeof(Vehicle)            = 56
sizeof(Truck)              = 72
sizeof(RefrigeratedTruck)  = 88
sizeof(PassengerCar)       = 104

### Diagram

![alt text](diagram.png)

### Conclusion  !

In this lab, I reinforced my practical skills in working with dynamic polymorphism and abstract classes in C++. I successfully implemented virtual method dispatch inside a loop for Truck, RefrigeratedTruck, and PassengerCar objects using an array of base Vehicle pointers.

Through this assignment, I focused on the following concepts:

Polymorphic Behavior: I learned why a plain array of objects is unsuitable (due to object slicing) and how an array of pointers preserves the polymorphic context.

Memory & vtable Inspection: Using a debugger, I verified that the first machine word of the object (8 bytes) holds the hidden virtual table pointer (vptr), followed by the data fields. This clearly explains the growth of sizeof from 56 to 104 bytes.

Additionally, I organized the classes into a clean structure and covered them with unit tests managed by CMake, all of which passed successfully.