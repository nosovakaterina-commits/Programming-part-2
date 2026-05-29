cmake_minimum_required(VERSION 3.14)
project(lab07_vehicles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

add_library(vehicles_hierarchy
    private/Vehicle.cpp
    private/Truck.cpp
    private/RefrigeratedTruck.cpp
    private/PassengerCar.cpp
)
target_include_directories(vehicles_hierarchy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public)

add_executable(lab07 main.cpp)
target_link_libraries(lab07 PRIVATE vehicles_hierarchy)

enable_testing()
add_executable(run_tests tests/test_vehicles.cpp)
target_link_libraries(run_tests PRIVATE vehicles_hierarchy GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)