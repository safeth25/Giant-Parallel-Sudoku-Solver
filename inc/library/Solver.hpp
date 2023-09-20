#include "Grid.hpp"
#pragma once

class Solver{
    public:

    Solver();

    bool checkRowValidity(Grid& sudoku,int num, int row);
    bool checkColumnValidity(Grid& sudoku,int num, int column);
    bool checkSubgridValidity(Grid& sudoku,int num, int row, int column);
    bool checkCellNumberValidity(Grid& sudoku, int num, int row, int column);
    bool checkSudokuValidity(Grid& sudoku);
    bool isEmptyCell(Grid& sudoku, int& row, int& column);
    bool backtrackingAlgorithm(Grid& sudoku);
};