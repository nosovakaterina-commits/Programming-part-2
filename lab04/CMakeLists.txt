cmake_minimum_required(VERSION 3.20)
project(StudentLab04 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)
enable_testing()

add_library(student_lib src/Student.cpp)
target_include_directories(student_lib PUBLIC include)
target_compile_features(student_lib PUBLIC cxx_std_20)

add_executable(student_app src/main.cpp)
target_link_libraries(student_app PRIVATE student_lib)

add_executable(student_tests 
    tests/test_main.cpp 
    tests/test_Student.cpp
)

target_link_libraries(student_tests PRIVATE student_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(student_tests)