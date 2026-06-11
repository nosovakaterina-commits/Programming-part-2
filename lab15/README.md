# Lab 15 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _11_06_26
**Varient:** _1_

---
# Task Description

STL Algorithms, Lambda Expressions, and Functors in C++
Create a library book catalog system using a vector of structures. Implement automated data generation using a random engine. Perform data processing operations including: finding available books by an author using predicates, counting elements matching specific conditions, sorting by multiple criteria (year and title), and removing records using the erase-remove idiom.

---

## Structure

```text
lab14/
├── assets/
├── src/ 
    ├── main.cpp
    |__ BookCatologe.cpp
├── include/
    |__ BookCatologe.hpp
├── tets/
    |__ test_book_catologe.cpp
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

The goal of this lab is to acquire practical skills in applying standard C++ algorithms for processing collections of domain objects, constructing predicates, comparators, function objects, and lambda expressions, as well as generating reproducible
test data using the <random> library.

In this lab, I completed the following tasks:
Create a library book catalog system using a vector of structures. Implement automated data generation using a random engine. Perform data processing operations including: finding available books by an author using predicates, counting elements matching specific conditions, sorting by multiple criteria (year and title), and removing records using the erase-remove idiom.

---

### Test Results

![alt text](tests.png)

### Runtime Output
![alt text](result1.png)
![alt text](result2.png)

=== Initial Book Catalog ===
ID: 1 | Title: Book Volume 1 | Author: Stroustrup | Year: 2018 | Available: Yes
ID: 2 | Title: Book Volume 2 | Author: Martin | Year: 2016 | Available: Yes
ID: 3 | Title: Book Volume 3 | Author: Prata | Year: 2011 | Available: No
ID: 4 | Title: Book Volume 4 | Author: Stroustrup | Year: 1995 | Available: No
ID: 5 | Title: Book Volume 5 | Author: Martin | Year: 2006 | Available: Yes
ID: 6 | Title: Book Volume 6 | Author: Stroustrup | Year: 2011 | Available: No
ID: 7 | Title: Book Volume 7 | Author: Prata | Year: 2013 | Available: No
ID: 8 | Title: Book Volume 8 | Author: Martin | Year: 2024 | Available: Yes
ID: 9 | Title: Book Volume 9 | Author: King | Year: 2023 | Available: No
ID: 10 | Title: Book Volume 10 | Author: Martin | Year: 1996 | Available: Yes
ID: 11 | Title: Book Volume 11 | Author: Martin | Year: 2012 | Available: No
ID: 12 | Title: Book Volume 12 | Author: Prata | Year: 2008 | Available: No
ID: 13 | Title: Book Volume 13 | Author: Stroustrup | Year: 1990 | Available: No
ID: 14 | Title: Book Volume 14 | Author: Prata | Year: 2012 | Available: No
ID: 15 | Title: Book Volume 15 | Author: Martin | Year: 1991 | Available: No
ID: 16 | Title: Book Volume 16 | Author: King | Year: 2003 | Available: No
ID: 17 | Title: Book Volume 17 | Author: Stroustrup | Year: 1993 | Available: Yes
ID: 18 | Title: Book Volume 18 | Author: Prata | Year: 1997 | Available: No
ID: 19 | Title: Book Volume 19 | Author: Prata | Year: 2025 | Available: Yes
ID: 20 | Title: Book Volume 20 | Author: Stroustrup | Year: 1991 | Available: Yes

First available book by Stroustrup: Book Volume 1 (2018)

Number of books published after 2010: 10
Has books older than year 2000: Yes

=== Sorted Catalog (by Year and Title) ===
ID: 13 | Title: Book Volume 13 | Author: Stroustrup | Year: 1990 | Available: No
ID: 15 | Title: Book Volume 15 | Author: Martin | Year: 1991 | Available: No
ID: 20 | Title: Book Volume 20 | Author: Stroustrup | Year: 1991 | Available: Yes
ID: 17 | Title: Book Volume 17 | Author: Stroustrup | Year: 1993 | Available: Yes
ID: 4 | Title: Book Volume 4 | Author: Stroustrup | Year: 1995 | Available: No
ID: 10 | Title: Book Volume 10 | Author: Martin | Year: 1996 | Available: Yes
ID: 18 | Title: Book Volume 18 | Author: Prata | Year: 1997 | Available: No
ID: 16 | Title: Book Volume 16 | Author: King | Year: 2003 | Available: No
ID: 5 | Title: Book Volume 5 | Author: Martin | Year: 2006 | Available: Yes
ID: 12 | Title: Book Volume 12 | Author: Prata | Year: 2008 | Available: No
ID: 3 | Title: Book Volume 3 | Author: Prata | Year: 2011 | Available: No
ID: 6 | Title: Book Volume 6 | Author: Stroustrup | Year: 2011 | Available: No
ID: 11 | Title: Book Volume 11 | Author: Martin | Year: 2012 | Available: No
ID: 14 | Title: Book Volume 14 | Author: Prata | Year: 2012 | Available: No
ID: 7 | Title: Book Volume 7 | Author: Prata | Year: 2013 | Available: No
ID: 2 | Title: Book Volume 2 | Author: Martin | Year: 2016 | Available: Yes
ID: 1 | Title: Book Volume 1 | Author: Stroustrup | Year: 2018 | Available: Yes
ID: 9 | Title: Book Volume 9 | Author: King | Year: 2023 | Available: No
ID: 8 | Title: Book Volume 8 | Author: Martin | Year: 2024 | Available: Yes
ID: 19 | Title: Book Volume 19 | Author: Prata | Year: 2025 | Available: Yes

Oldest book year: 1990
Newest book year: 2025

Average publication year: 2006.8

First scaled indicator: 10.0

=== Catalog After Removing Unavailable Books ===
ID: 20 | Title: Book Volume 20 | Author: Stroustrup | Year: 1991 | Available: Yes
ID: 17 | Title: Book Volume 17 | Author: Stroustrup | Year: 1993 | Available: Yes
ID: 10 | Title: Book Volume 10 | Author: Martin | Year: 1996 | Available: Yes
ID: 5 | Title: Book Volume 5 | Author: Martin | Year: 2006 | Available: Yes
ID: 2 | Title: Book Volume 2 | Author: Martin | Year: 2016 | Available: Yes
ID: 1 | Title: Book Volume 1 | Author: Stroustrup | Year: 2018 | Available: Yes
ID: 8 | Title: Book Volume 8 | Author: Martin | Year: 2024 | Available: Yes
ID: 19 | Title: Book Volume 19 | Author: Prata | Year: 2025 | Available: Yes


## Conclusion

In this lab I learn how to use Standard Template Library (STL) algorithms effectively, write lambda expressions with different capture modes, and implement custom functors with internal state to automate data processing and completely eliminate manual loops.

In my version of the program, I wrote code that that creates a library book catalog, generates structured random data using a Mersenne Twister engine, filters and counts available books using dynamic predicates, sorts the catalog by multiple criteria, and safely removes unavailable records using the erase-remove idiom.