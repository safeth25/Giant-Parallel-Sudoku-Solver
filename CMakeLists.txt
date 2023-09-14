cmake_minimum_required(VERSION 3.16.3)

project(ParallelizedSudokuSolver

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON))

add_executable(simulate ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)