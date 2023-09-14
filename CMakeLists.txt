cmake_minimum_required(VERSION 3.16.3)

project(ParallelizedSudokuSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(inc)
add_subdirectory(src)

add_executable(solve ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(solve 
    PRIVATE library
    )