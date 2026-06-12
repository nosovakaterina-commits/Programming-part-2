cmake_minimum_required(VERSION 3.20)
project(Lab16_ContainerVariant1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab16_main src/main.cpp)
target_include_directories(lab16_main PRIVATE include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(vector_test tests/test_vector.cpp)
target_link_libraries(vector_test PRIVATE GTest::gtest_main)
target_include_directories(vector_test PRIVATE include)

add_executable(list_test tests/test_list.cpp)
target_link_libraries(list_test PRIVATE GTest::gtest_main)
target_include_directories(list_test PRIVATE include)

include(GoogleTest)
gtest_discover_tests(vector_test)
gtest_discover_tests(list_test)