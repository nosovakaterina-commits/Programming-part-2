cmake_minimum_required(VERSION 3.10)
project(StudentProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)

add_executable(student_app 
    src/main.cpp 
    src/Student.cpp
)