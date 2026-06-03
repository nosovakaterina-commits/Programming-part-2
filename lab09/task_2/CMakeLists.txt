cmake_minimum_required(VERSION 3.15)
project(Lab09_Task2)

include_directories(public)

set(SOURCES
    private/Student.cpp
    private/Athlete.cpp
    private/CollegeAthlete.cpp
)

# Виконуваний файл для запуску самої програми Task 2 
add_executable(task2_exe ${SOURCES} main.cpp)
add_executable(task2_tests ${SOURCES} tests/test_task_2.cpp)
target_link_libraries(task2_tests gtest_main)
