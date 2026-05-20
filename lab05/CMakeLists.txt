cmake_minimum_required(VERSION 3.14)
project(UniversitySystem CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(public)

set(CORE_SOURCES
    private/Course.cpp
    private/Department.cpp
    private/Professor.cpp
    private/Student.cpp
    private/University.cpp
)

add_executable(university_app main.cpp ${CORE_SOURCES})

add_executable(university_tests 
    tests/test_main.cpp
    tests/test_University.cpp
    ${CORE_SOURCES}
)

target_link_libraries(university_tests gtest gtest_main)

enable_testing()
add_test(NAME AllUniversityTests COMMAND university_tests)