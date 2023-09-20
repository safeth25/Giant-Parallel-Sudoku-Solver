#include "library/Solver.hpp"

Solver::Solver(){}

bool Solver::checkRowValidity(Grid& sudoku,int num, int row){
    // Checks the row.
    for(int column = 0; column < sudoku.gridSize; column++){
        if(sudoku.grid[row][column] == num){
            return false;
        }
    }
    return true;
}
bool Solver::checkColumnValidity(Grid& sudoku,int num, int column){
    // Checks the column
    for(int row = 0; row < sudoku.gridSize; row++){
        if(sudoku.grid[row][column] == num){
            return false;
        }
    }
    return true;
}
bool Solver::checkSubgridValidity(Grid& sudoku,int num, int row, int column){
    // Checks the NxN subgrid.
    int gridSize = std::sqrt(sudoku.gridSize);
    int startRow = row - (row % gridSize);
    int startColumn = column - (column % gridSize);

    for(int i = 0; i < gridSize; i++){
        for(int k = 0; k < gridSize; k++){
            if(sudoku.grid[i + startRow][k + startColumn] == num){
                return false;
            }
        }
    }
    return true;
}
/**
 * Checks that the same number is not present in the current row, column and 3x3 subgrid
*/
bool Solver::checkCellNumberValidity(Grid& sudoku,int num, int row, int column){
    // Checks the row
    bool rowValidity = checkRowValidity(sudoku, num, row);

    // Checks the column
    bool columnValidity = checkColumnValidity(sudoku, num, column);

    // Checks the NxN subgrid
    bool subgridValidity = checkSubgridValidity(sudoku, num, row, column);

    // Returns true, when all three tests are true
    return std::min(std::min(rowValidity, columnValidity), subgridValidity);
}

//TO-DO
bool Solver::checkSudokuValidity(Grid& sudoku){
    bool validity;
    for(int i = 0; i < sudoku.gridSize; i++){
        for(int k = 0; k < sudoku.gridSize; k++){

        }
    }
    return !validity;
}

bool Solver::isEmptyCell(Grid& sudoku, int& row, int& column){
    for(row = 0; row < sudoku.gridSize; row++){
        for(column = 0; column < sudoku.gridSize; column++){
            if(sudoku.grid[row][column] == UNASSIGNED){
                return true;
            }
        }
    }
    return false;
}

bool Solver::backtrackingAlgorithm(Grid& sudoku){
    int row = 0;
    int column = 0;
    if(!isEmptyCell(sudoku, row, column)){
        return true;
    }
    for(int num = 1; num <= sudoku.gridSize; num++){
        if(checkCellNumberValidity(sudoku, num, row, column)){
            sudoku.setCellValueAt(num, row, column);
            if(backtrackingAlgorithm(sudoku)){
                return true;
            }
            sudoku.setCellValueAt(UNASSIGNED, row, column);
        }
    }
    return false;
}