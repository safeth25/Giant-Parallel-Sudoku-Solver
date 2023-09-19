project(ParallelizedSudokuSolver)

add_library(library Parser.cpp Solver.cpp Grid.cpp) 

target_include_directories(library
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc
)