cmake_minimum_required(VERSION 3.12)
project(problem_098_code CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(code main.cpp)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # Optimize but avoid forcing static libs to maximize portability on OJ
  target_compile_options(code PRIVATE -O2 -pipe)
endif()
