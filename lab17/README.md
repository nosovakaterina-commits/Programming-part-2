# Lab 17 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _12_06_26
**Varient:** _1_

---
# Task Description

The objective of this lab is to design and implement custom template containers for a dynamic array and a singly linked list with C++20 compliant iterators, and to integrate them with STL algorithms to manage and manipulate collection data based on a custom Book structure.

---

## Structure

```text
lab17/
├── assets/
├── src/ 
    ├── main.cpp
    |__ catalog.cpp
├── include/
    ├── book.h
    |__ catalog.h
├── tets/
    |__ test_catalog.cpp
├── CMakeLists.txt
|__ README.md

```

# Lab Instructions

To achieve this objective, the following steps are required:
• define a domain record type and prepare a test data set according to the individual variant;
• build an index based on std::map or std::unordered_map;
• use std::set or std::unordered_set to maintain unique values;
• perform grouping or store duplicate values using std::multimap, std::unordered_multimap, std::multiset, or std::unordered_multiset;
• compare ordered and unordered data access models;
• implement a small extension with a custom key class or a callable object;
• implement a separate scenario with a container adapter.

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
./lab17_main
./test_catalog
```
 
### Report

The goal of this lab is to develop practical skills in the use of C++ associative containers and container adapters for storing, searching, indexing, grouping, and performing specialized processing of domain objects.


In this lab, I completed the following tasks:
Implemented a comprehensive library catalog system by utilizing basic associative containers like std::map, std::set, and std::multimap for multi-level book indexing, analyzing publication year frequencies via std::unordered_map, creating a composite key with a custom hash function for std::unordered_set, and managing a FIFO reader request queue using the std::queue container adapter.

---

### Test Results

![alt text](test.png)

### Runtime Output
![alt text](result.png)

Library catalog initialized successfully.
Total books indexed: 20
Unique authors count: 13

## Conclusion

In this lab I developed practical skills in the use of C++ associative containers and container adapters for storing, searching, indexing, grouping, and performing specialized processing of domain objects.

In my version of the program, I developed a library catalog system in C++, where we successfully implemented book indexing and analysis using std::map, std::set, and std::multimap, organized a composite key search with a custom hashing functor in std::unordered_set, and configured FIFO processing of reader requests via the std::queue adapter.