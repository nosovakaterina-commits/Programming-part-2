# Lab 16 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _11_06_26
**Varient:** _1_

---
# Task Description

Implement custom template containers for a singly linked list and a dynamic array with C++20 compliant iterators, integrate them with STL algorithms using a Book structure.

---

## Structure

```text
lab16/
├── assets/
├── src/ 
    ├── main.cpp
├── include/
    ├── book.hpp
    ├── simple_forward_list.hpp
    |__ simple_vector.hpp
├── tets/
    ├── test_vector.cpp
    |__ test_list.cpp
├── CMakeLists.txt
|__ README.md

```

# Lab Instructions

To achieve this objective, the following tasks must be completed:
• explain the role of an iterator as a connection between a container, a range, and an algorithm;
• implement a vector-like container with correct management of storage, object lifetime, capacity, and size;
• add pointer iterators to the vector-like container through begin(), end(), cbegin(), and cend();
• implement a node-based container with a separate iterator class;
• add const_iterator and provide correct const iteration;
• verify custom iterators through range-for, standard algorithms, and compile-time checks based on C++20 concepts;
• prepare GoogleTest tests for the container, iterator, const iterator, algorithms, and edge cases.

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
./lab16_main
./vector_test
./list_test
```
 
### Report

The goal of this lab is to acquire practical skills in implementing a sequence container and an STL-like iterator in C++. The work involves organizing element storage, implementing the basic operations of a container, providing an iteration interface, checking compatibility with range-for and standard algorithms, and comparing pointer iterators for a contiguous container with a separate iterator class for a singly linked list.

In this lab, I completed the following tasks:
Library Book Catalog
• Record fields: id, title, author, year, available.
• Required operations: find books published after a specified year;
count available books; remove unavailable booksm.

The assignment requires implementing custom template containers for a singly linked list and a dynamic array to manage a Book catalog by finding books published after a specific year, counting available copies, and removing unavailable records using the STL Erase-Remove idiom.

---

### Test Results

![alt text](tests.png)

### Runtime Output
![alt text](result.png)

--- Testing SimpleForwardList (Node-based) ---
Found by std::find_if: 1984 (1949)

Books published after 1950:
 - Neuromancer (1984)
 - Dune (1965)
 - Foundation (1951)

--- Testing SimpleVector (Contiguous) ---
Number of available books in vector: 2

Vector contents after removing unavailable books:
 - The Hobbit [Available: true]
 - Dune [Available: true]

## Conclusion

In this lab I gained practical skills in implementing a sequence container and an STL-like iterator in C++. The work includes organizing the element storage, implementing the basic container operations, providing an iteration interface, checking compatibility with range-for and standard algorithms, and comparing pointer iterators for a contiguous container with a separate class of iterators for a singly linked list.

In my version of the program, I wrote code that implements custom template structures for a dynamic vector and a singly linked list with C++20 compliant iterators, successfully managing a library book catalog through standard STL algorithms