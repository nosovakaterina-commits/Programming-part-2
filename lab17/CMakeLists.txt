cmake_minimum_required(VERSION 3.20)
project(lab17_library)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(lab17_main
    src/main.cpp
    src/catalog.cpp
)
target_include_directories(lab17_main PUBLIC include)

add_executable(test_catalog 
    tests/test_catalog.cpp
    src/catalog.cpp
)
target_include_directories(test_catalog PUBLIC include)
target_link_libraries(test_catalog GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_catalog)