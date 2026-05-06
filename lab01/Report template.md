# Lab 01 — Lab Work Report Template
 
---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _24_03_26_  
 
---
 
## Task Description
 
> Managing the build process of C++ projects and dependencies using CMake,
GoogleTest, a modular structure, and vcpkg.

 
## Structure
 
```text
varient_1/
├── app/
    |__ main.cpp
├── lib/
    ├── include/
        |__ math_utils.hpp
    ├── src/
        |__ math_utils.cpp
├── tests/
    |__ test_math_utils.cpp
├── CMakeLists.txt
└── vcpkg.json
```
 
## Lab Instructions
 
All variants are completed according to the same incremental scheme:
1) create a simple executable project;
2) isolate part of the logic into a separate library;
3) add tests for the library through GoogleTest;
4) move the configuration into a modular structure through add_subdirectory();
5) connect one external library through vcpkg (the recommended choice is fmt)
 
### How to Build
```bash
cd varient_1
cmake -S . -B build
cmake --build build
```
 
### How to Run Tests
 
```bash
cd build
./app
```
 
### How to Generate Coverage
```bash
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```
![alt text](<screen for retort/how to generate coverage.png>)
 
## Report
 
The goal of this lab is to  acquire practical skills in creating C++ projects, configuring the build process,
connecting custom libraries, organizing a modular structure, integrating tests, and adding
external dependencies.
 
In this lab, I completed the following tasks:
 The library performs the operations add, sub,
mul, div. 
---

 
### Build Results
 
![alt text](<screen for retort/build.png>)
 
---
 
### Test Results
 
> ![alt text](<screen for retort/terminal.png>)
 
>### Runtime Output
 
>4 + 8 = 12
9 - 7 = 16
3 * 24 = 27
15 / 3 = 19
 
---
 
### Code Coverage
 
> Internal ctest changing into directory: /home/cer_nosova_kate/programming-part-2/varient_1/build
Test project /home/cer_nosova_kate/programming-part-2/varient_1/build
    Start 1: MathUtilsTest.AddWorks
1/4 Test #1: MathUtilsTest.AddWorks ...........   Passed    0.00 sec
    Start 2: MathUtilsTest.SubWorks
2/4 Test #2: MathUtilsTest.SubWorks ...........   Passed    0.00 sec
    Start 3: MathUtilsTest.MulWorks
3/4 Test #3: MathUtilsTest.MulWorks ...........   Passed    0.00 sec
    Start 4: MathUtilsTest.DivWorks
4/4 Test #4: MathUtilsTest.DivWorks ...........   Passed    0.00 sec

100% tests passed, 0 tests failed out of 4

Total Test time (real) =   0.02 sec
---
### Observations and Conclusion
 
>I structured the project into app, lib, and tests folders and configured CMakeLists.txt for a complete build cycle.

Connected a custom math_utils library using add_library and target_link_libraries.

I used GoogleTest for unit testing, FetchContent to download it, and vcpkg for package management.
 
---
 