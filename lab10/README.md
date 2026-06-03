# Lab 10 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _3_06_26

---
# Task Description  !

Develop a small header-only utility module for measurement processing using function templates.

---

## Structure

```text
lab06/
├── assets/
├── include/
    |__ varient_utils.h
├── tests/
    |__ test_varient_utils.cpp
├── CMakeLists.txt
├── main.cpp
|__ README.md
```

# Lab Instructions

For each variant, the student must:
1. analyze the selected task set and identify the required generic operations;
2. implement the required function templates in a header-based utility module;
3. use meaningful function names, parameter names, and concise comments where needed;
4. place template declarations and definitions in include/ or another header-only directory;
5. create a demonstration program in main.cpp;
6. create unit tests for the key templates using a unit testing framework such as Google Test;
7. test the templates on at least two primitive or standard-library types where this is meaningful;
8. include boundary and negative cases in the tests whenever the task naturally requires them;
9. explain which operations or properties are required from the template arguments;
10. build the project using CMakeLists.txt.


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
./lab10_main
./lab10_tests
```
 
### Report

The goal of this lab is todevelop practical skills in designing and implementing reusable function templates in C++.

In this lab, I completed the following tasks:
Required tasks:
1) Implement maxValue() and minValue() for two values of the same type.
2) Implement clampValue() that restricts a value to a closed interval.
3) Implement average() for an array of numeric values.
Minimum testing scope:
• Test the functions with int and double.
• Check boundary cases in clampValue() and a single-element array in average().
Suggested technical focus: same-type template deduction, arithmetic assumptions, and edge-case handling
---

### Test Results

![alt text](test_1.png)
![alt text](test_2.png)

### Runtime Output

![alt text](result.png)
Max: 42
Min: 17
Clamp 50: 50
Average int: 3.000

### Conclusion

In this lab I learn how to develop a small header-only utility module for measurement processing using function templates.


In my version of the program, I wrote code that implements a compact header module for processing measurements, which contains universal function templates for finding the maximum and minimum, limiting the value in a given region, and calculating the arithmetic mean of a data array of any numeric type.