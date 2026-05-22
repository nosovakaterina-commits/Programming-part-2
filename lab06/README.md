# Lab 05 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _21_05_26

---
# Task Description

 Implement an object-oriented model of a car  system using composition

---

## Structure

```text
lab06/
├── assets/
├── private/
    ├── Car.cpp
    ├── Engine.cpp
    ├── Wheel.cpp
    ├── Seat.cpp
    |__ Transmission.cpp
├── public/
    ├── Car.hpp
    ├── Engine.hpp
    ├── Wheel.hpp
    ├── Seat.hpp
    |__ Transmission.hpp
├── uml/
    |__ diagram.puml
├── tets/
    |__ test_Student.cpp
├── CMakeLists.txt
├── main.cpp
|__ README.md
```

# Lab Instructions

For each variant, the student must:
1. analyze the problem domain and identify the main entities;
2. design the required classes and their responsibilities;
3. establish composition relationships where appropriate;
4. implement each class in a separate source file;
5. draw a UML class diagram that shows classes, attributes, methods, associations,
and multiplicities;
6. implement a demonstration program in main.cpp;
7. create unit tests for the key classes using a unit testing framework such as Google
Test;
8. organize the project as a structured CMake-based directory;
9. follow consistent naming conventions and add concise meaningful comments
where needed.

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
./car_tests
./car_app
```
 
### Report

The goal of this lab is to practice modeling class relationships in which one object is built from integral parts whose lifetime is conceptually controlle by the whole.

In this lab, I completed the following tasks:
Implement an object-oriented model of a car  system using composition

---

### Test Results

![alt text](test.png)
Test project /home/cer_nosova_kate/programming-part-2/lab06/build
    Start 1: CarTest.StartsWorkingAfterEngineOn
1/4 Test #1: CarTest.StartsWorkingAfterEngineOn ................   Passed    0.00 sec
    Start 2: CarTest.AccelerationIncreasesSpeed
2/4 Test #2: CarTest.AccelerationIncreasesSpeed ................   Passed    0.00 sec
    Start 3: CarTest.AccelerationConsumesMoreFuelThanBraking
3/4 Test #3: CarTest.AccelerationConsumesMoreFuelThanBraking ...   Passed    0.00 sec
    Start 4: CarTest.BrakingDecreasesSpeed
4/4 Test #4: CarTest.BrakingDecreasesSpeed .....................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 4

Total Test time (real) =   0.02 sec

### Runtime Output

![alt text](result.png)

Engine started.
Car accelerated. Speed: 10 km/h
Car accelerated. Speed: 20 km/h
Current speed: 20 km/h
Engine RPM: 2000 rpm
Remaining fuel: 58 L
Car braked. Speed: 10 km/h
Car refueled. Current fuel: 60 L
Engine stopped.

### Diagram

![alt text](diagram.png)

### Conclusion  !

In this lab I learn how to practice modeling class relationships in which one object is built from integral parts whose lifetime is conceptually controlle by the whole.

In my version of the program, I wrote code that implements direct composition by making the Engine, Transmission, Wheel, and Seat objects strictly part of the Car class by value, ensuring their lifetimes are completely tied to the lifecycle of the vehicle.