cmake_minimum_required(VERSION 3.14)
project(Lab14_SequenceContainers LANGUAGES CXX)

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

include_directories(include)

add_executable(lab14_main
    src/main.cpp
    src/record.cpp
    src/container_analyzer.cpp
)

add_executable(lab14_tests
    tests/test_lab14.cpp
    src/record.cpp
    src/container_analyzer.cpp
)

target_link_libraries(lab14_tests gtest_main gtest)

enable_testing()
add_test(NAME Lab14ValidationTest COMMAND lab14_tests)

add_custom_command(TARGET lab14_main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/data
    $<TARGET_FILE_DIR:lab14_main>/data
)

add_custom_command(TARGET lab14_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/data
    $<TARGET_FILE_DIR:lab14_tests>/data
)