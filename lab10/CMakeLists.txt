cmake_minimum_required(VERSION 3.14)
project(Lab10_MeasurementUtilities CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(lab10_main main.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lab10_tests tests/test_variant_utils.cpp)
target_link_libraries(lab10_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab10_tests)