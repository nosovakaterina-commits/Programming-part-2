cmake_minimum_required(VERSION 3.14)
project(Lab15_Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(catalog_lib src/BookCatalog.cpp include/BookCatalog.hpp)

add_executable(lab15_main src/main.cpp)
target_link_libraries(lab15_main catalog_lib)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lab15_tests tests/test_book_catalog.cpp)
target_link_libraries(lab15_tests gtest_main catalog_lib)

target_include_directories(lab15_tests PRIVATE include)

include(GoogleTest)
gtest_discover_tests(lab15_tests)