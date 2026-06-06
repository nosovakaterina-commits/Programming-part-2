cmake_minimum_required(VERSION 3.14)
project(lab12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

include_directories(include)

add_library(lab12_lib
    src/Student.cpp
    src/Student_array.cpp
    src/Smart_nodes.cpp
)

add_executable(lab12_main main.cpp)
target_link_libraries(lab12_main lab12_lib)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(lab12_tests tests/test_resource.cpp)
target_link_libraries(lab12_tests lab12_lib gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(lab12_tests)