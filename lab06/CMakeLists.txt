cmake_minimum_required(VERSION 3.14)
project(Car LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

add_library(car_core
    private/Car.cpp
    private/Engine.cpp
    private/Wheel.cpp
    private/Seat.cpp
    private/Transmission.cpp
)

target_include_directories(car_core PUBLIC public)

add_executable(car_app main.cpp)
target_link_libraries(car_app PRIVATE car_core)

add_executable(car_tests tests/test_car.cpp)
target_link_libraries(car_tests PRIVATE car_core GTest::gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(car_tests)