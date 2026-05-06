cmake_minimum_required(VERSION 3.20)
project(varient_1 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(math_utils lib/src/math_utils.cpp)
target_include_directories(math_utils PUBLIC lib/include)
target_compile_features(math_utils PUBLIC cxx_std_20)

add_executable(app app/main.cpp)
target_link_libraries(app PRIVATE math_utils)

add_executable(math_utils_tests tests/test_math_utils.cpp)
target_link_libraries(math_utils_tests PRIVATE math_utils GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(math_utils_tests)