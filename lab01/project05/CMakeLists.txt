cmake_minimum_required(VERSION 3.20)
project(project05 LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)

add_dependencies(project05 main.cpp)
target_link_libraries(project05 PRIVATE fmt::fmt)
target_compile_features(project05 PRIVATE cxx_std_20)