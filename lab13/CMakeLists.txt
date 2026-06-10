cmake_minimum_required(VERSION 3.14)
project(lab13_tickets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/data)

add_library(tickets_lib
    private/StringUtils.cpp
    private/Ticket.cpp
    private/TicketProcessor.cpp
)

target_include_directories(tickets_lib PUBLIC public)

add_executable(lab13_main main.cpp)
target_link_libraries(lab13_main tickets_lib)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(lab13_tests tests/test_tickets.cpp)
target_link_libraries(lab13_tests tickets_lib gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(lab13_tests)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)