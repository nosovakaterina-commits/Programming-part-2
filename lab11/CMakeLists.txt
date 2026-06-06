cmake_minimum_required(VERSION 3.14)
project(Lab11_ClassTemplates CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(lab11_main main.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lab11_tests tests/test_grade_book.cpp)

target_link_libraries(lab11_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab11_tests)