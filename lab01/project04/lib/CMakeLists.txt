add_library(math_utils src/math_utils.cpp)

target_include_directories(math_utils PUBLIC include)
target_compile_features(math_utils PUBLIC cxx_std_20)