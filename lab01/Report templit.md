# Lab 02 - Text I/O, formatting, and file output
 
---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _Katerina_Nosova_  
**Date:** _20_04_26_  
 
---
 
## Task Description
 
Task01 - write a program that outputs the following data to the console
Task02 - write a program that reads from the keyboard.
Task03 - write a program that outputs a formatted table with at least five rows. Each row must contain.
Task04 - write a program that outputs the same floating-point number in several formats.
Task05 - write a program that outputs the same integer value in the following numeral systems.
Task06 - write a program that creates a text file and writes a formatted table into it.
Task07 - write a program that outputs several Boolean values twice.
Task08 - write a program that creates a text report in a file. 
Task09 - rewrite one of the previous console
output tasks using std::format.
Task10 - write a program that outputs several formatted lines using std::print and std::println.
Task11 - implement one small output scenario in
three ways.
 
## Structure
 
```text
lab02/
├── task01/
        ├── CMakeLists.txt
        └── main.cpp
├── task02/
        ├── CMakeLists.txt
        └── main.cpp
├── task03/
        ├── CMakeLists.txt
        └── main.cpp
├── task04/
        ├── CMakeLists.txt
        └── main.cpp
├── task05/
        ├── CMakeLists.txt
        └── main.cpp
├── task06/
        ├── CMakeLists.txt
        └── main.cpp
├── task07/
        ├── CMakeLists.txt
        └── main.cpp
├── task08/
        ├── CMakeLists.txt
        └── main.cpp
├── task09/
        ├── CMakeLists.txt
        └── main.cpp
├── task10/
        ├── CMakeLists.txt
        └── main.cpp
├── task11/
        ├── CMakeLists.txt
        └── main.cpp
└── Report.md
```
 
## Lab Instructions
 
Task01 -  Task must include name, group, an integer value, a floating-point value, a Boolean value.
The output must contain explanatory labels and line breaks
Task02 - Task must include an integer, a floating-point value, a word, a full line of text.
After reading the data, output the entered values to the console in a clear and readable form.
Task03 - . Each row must contain:
• an index;
• a name or label;
• an integer value;
• a floating-point value.
Use std::setw(), alignment manipulators such as std::left or std::right,
and precision control to make the table neat and readable.
Task04 - Task must include default format, fixed notation, scientific notation, fixed notation with two digits after the decimal point, fixed notation with five digits after the decimal point.
Briefly compare the produced output
Task05 - Task mmust iclude decimal, hexadecimal,octal systems.
Use appropriate manipulators and add textual labels to each line
Task06 -  The table must contain at least five rows and
at least four columns. Use std::setw() together with alignment manipulators such as
std::left or std::right so that the file content is aligned and readable.
After writing the file, make sure that the file can be opened and its content matches
the intended layout.
Task07 - Task must include in the default numeric form with std::boolalpha.
Explain the difference in the output.
Task08 -  The report must contain:
• a title;
• several labeled values;
• a separator line;
• a short summary line.
Use stream formatting tools to make the report visually clear.
Task09 - . Use placeholders, width control, and precision control
where appropriate.
Compare the readability of the resulting code with the version based on std::cout
and <iomanip>.
Task10 - . The program
must include:
• integer output;
• floating-point output with precision control;
• aligned string output.
Task11 - Task must be with std::cout, with std::format, with std::println.
Then briefly describe which variant looks more readable and why.
 
### How to Build
 
```bash
cmake -S . -B build
cmake --build build
```
 
### How to Run Tests
 
```bash
./build/task01
```

## Report
 
The goal of this lab is to develop practical skills in using text input and output facilities in modern C++. The main focus is on the standard stream
library, formatted output with stream manipulators, formatted output to text files, and
modern formatting tools introduced in C++20 and C++23
 
TBD
---

### Test Results
 
![alt text](task01.png)
![alt text](task02.png)
![alt text](task03.png)
![alt text](task04.png)
![alt text](task05.png)
![alt text](task06.png)
![alt text](task06.2.png)
![alt text](task07.png)
![alt text](itask08.png)
![alt text](task08.2.png)
![alt text](task09.png)
![alt text](task10.png)
![alt text](task11.png)
 
---
 
### Observations and Conclusion
 
In this lab, I successfully implemented 11 tasks covering the full spectrum of I/O operations. I learned how to manage output precision, work with different numeral systems, and utilize the latest C++20/23 features to write cleaner and more maintainable code.
 
TBD
 
---
 