#include "Grid.hpp"
#pragma once

class Solver{
    public:

    Solver();

    bool checkCellNumberValidity(Grid sudoku, int row, int column);
};