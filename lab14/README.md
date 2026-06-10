# Lab 14 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _09_06_26
**Varient:** _1_

---
# Task Description

Create the basic record type for the individual variant with the fields listed in Variant Selection. Prepare at least 1000 test records, or another number sufficient for a visible comparison of operation execution tim
---

## Structure

```text
lab14/
├── assets/
├── src/
    ├── record.cpp
    ├── main.cpp
    |__ expected_report.cpp
├── include/
    ├── record.cpp
    |__ expected_report.cpp
├── data/
    ├── expected_report.txt
    |__ input.txt
├── tets/
    |__ test_lab14.cpp
├── CMakeLists.txt
|__ README.md

```

# Lab Instructions

To accomplish this objective, the following tasks must be completed:
• develop a basic record type for the domain area and prepare test data sets according to the individual variant;
• implement data storage and processing using three standard sequence containers specified by the variant: std::array, std::vector, std::deque, std::list, or std::forward_list;
• perform sequence traversal, searching, counting, insertion, deletion, and construction of a new sequence without using standard algorithms from <algorithm>;
• compare the containers in terms of element access, insertion at the beginning and at the end, insertion in the middle, deletion, traversal, and the execution time of typical operations;
• separately repeat part of the experiments after replacing selected record fields with std::shared_ptr and std::unique_ptr;
• investigate changes in the capacity of std::vector, iterator invalidation, and the difference between push_back() and emplace_back().

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
./lab1_main
./lab14_tests
```
 
### Report

The goal of this lab is to acquire practical skills in using standard C++ sequence containers to store, process, and comparatively analyze sets of domain-specific.
objects

In this lab, I completed the following tasks:
Task 1. Prepare Test Data and Three Containers.

Task 2. Implement Operations and Perform Timing Measurements.

Task 3. Replace the Specified Field with std::shared_ptr.

Task 4. Replace the Specified Field with std::unique_ptr.

Task 5. Implement Element Access and Traversal.

Task 6. Investigate std::vector Capacity Changes and Iterator Invalidation.
---

### Test Results

![alt text](tests.png)

### Runtime Output
![alt text](result.png)
![alt text](result2.png)
Vector growth -> Elements: 3, Capacity: 4
Vector growth -> Elements: 5, Capacity: 8
Vector growth -> Elements: 9, Capacity: 16

Found passenger for Kyiv: Alex
Tickets above 200: 2
Total revenue: 970
Filtered sequence size (Kyiv only): 2

--- Performance Benchmarking ---
Vector push_back: 508 us
Deque push_back: 320 us
List push_back: 477 us
### Conclusion  !

In this lab I learn how to practice modeling class relationships in which one object is built from integral parts whose lifetime is conceptually controlle by the whole.

In my version of the program, I wrote code that implements a database of domain-specific records using standard sequence containers, manages memory through std::shared_ptr and std::unique_ptr structures, tracks std::vector capacity growth, and benchmarks performance across different containers using low-level loops without the <algorithm> library.