# Lab 05 - Lab Work Report Template

---
**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Nosova_Kate_  
**Date:** _05_06_26
**Varient:** _1_ 

---
# Task Description

Resource management in C++ and the RAII idiom.

---

## Structure

```text
lab11/
├── assets/
    ├── uml/
        |__ diagram.puml
├── src/
    ├── Student.cpp
    ├── Student_array.cpp
    |__ Smart_nodes.cpp
├── include/
    ├── Student.h
    ├── Student_array.h
    ├── Simple_ptr.h
    |__ Smart_nodes.h
├── tets/
    |__ test_resource.cpp
├── CMakeLists.txt
├── main.cpp
|__ README.md
```

# Lab Instructions

1) The project must build as a self-contained C++ project.
2) Owned types must use separate .h/.cpp files unless the project structure justifies otherwise.
3) The manual dynamic array of objects from your type must use new[] and delete[] correctly.
4) The final array class from your variant must have no shallow copy, double release, or memory leak.
5) The Rule of Three and the Rule of Five must be implemented explicitly.
6) SimplePtr must demonstrate RAII and prohibit copying.
7) std::unique_ptr must be used for one object from your type and for an array of such objects.
8) At least one custom class must have a std::unique_ptr field.
9) The custom deleter is mandatory and must be meaningful.
10) std::shared_ptr must be used only where genuine shared ownership exists.
11) At least one custom class must have a std::shared_ptr field.
12) std::weak_ptr must be used to break a cyclic dependency or as a non-owning back-reference.
13) A diagnostic cycle example in a doubly linked list with two std::shared_ptr fields must be shown and then fixed with std::weak_ptr.
14) No manual delete must remain for resources transferred to smart pointers.
15) All key scenarios must appear in main() or in tests.

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
./lab12_tests
./lab12_main
```
 
### Report

The goal of this lab is to practise manual management of dynamic resources in C++, implement classes that own memory, apply the Rule of Three and the Rule of Five, use RAII, build a teaching wrapper SimplePtr, work with std::unique_ptr, std::shared_ptr, and std::weak_ptr, and define custom deleters for resources that cannot be released correctly with ordinary delete.

---

### Test Results

![alt text](test1.png)
![alt text](test2.png)

### Runtime Output

![alt text](result.png)

--- Student_array ---
Copied array size: 2 (Deep Copy Working)

--- std::unique_ptr & std::move ---
Moved student name: Ivan
Unique array element 0: Olga

--- Custom Deleter ---
Unique pointer with custom deleter created for: Daria
[Custom Deleter] Freeing Student memory at address: 0x62b8108db810

---  Cyclic References ---
1. Creating a cycle (Memory leak demonstration):
  Cycle created between Node_A and Node_B. Leaving scope block...
  (Notice: No node destructors were called above! Memory leaked!)

2. Breaking the cycle using std::weak_ptr:
  Safe structure created. Leaving scope block...
[Smart_nodes Destructor] Node_A (Safe Test) successfully freed from memory.
[Smart_nodes Destructor] Node_B (Safe Test) successfully freed from memory.

### Diagram

![alt text](diagram.png)

### Conclusion  !

In this lab I learn how to practise manual management of dynamic resources in C++, implement classes that own memory, apply the Rule of Three and the Rule of Five, use RAII, build a teaching wrapper SimplePtr, work with std::unique_ptr, std::shared_ptr, and std::weak_ptr, and define custom deleters for resources that cannot be released correctly with ordinary delete.


In my version of the program, I wrote code that implements a custom dynamic array named Student_array adhering strictly to the Rule of Five to ensure safe manual memory management. Furthermore, the program thoroughly demonstrates modern C++ smart pointers, showcasing exclusive ownership transfer with std::unique_ptr and std::move, alongside a custom deleter configuration for tailored resource cleanup. Finally, it addresses complex memory behavior by illustrating how cyclic references within std::shared_ptr networks induce memory leaks, and effectively proves how incorporating std::weak_ptr breaks these cycles to guarantee automated, leak-free object destruction.