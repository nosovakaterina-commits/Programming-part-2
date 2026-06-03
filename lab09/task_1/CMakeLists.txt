cmake_minimum_required(VERSION 3.15)
project(Lab09_Task1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(public)

set(SOURCES
    private/Device.cpp
    private/InputDevice.cpp
    private/OutputDevice.cpp
    private/TouchDisplay.cpp
)

# Виконуваний файл для запуску програми Task 1
add_executable(task1_exe ${SOURCES} main.cpp)

# Підключаємо тести Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE # Опція, яка прибирає назойливе попередження компілятора
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Виконуваний файл для тестів Task 1
add_executable(task1_tests ${SOURCES} tests/test_task_1.cpp)
target_link_libraries(task1_tests gtest_main)
