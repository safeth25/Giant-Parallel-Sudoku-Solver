#include <vector>
#include <iostream>
#include <fstream>

#pragma once
#define UNASSIGNED 0

class Grid{

    public:
    
    //  Die Größe des Sudoku-Gitters (z.B., 9 für ein 9x9-Gitter)
    int gridSize;

    // Die Matrix zur Speicherung der Sudoku-Zahlen
    std::vector<std::vector<int>> grid;

    Grid(int gridSize);

    void displaySudoku();

    void readSudokuFromFile(std::string filename);

    void writeSudokuToFile();

    int getCellValueAt(int row, int column);

    void setCellValueAt(int value, int row, int column);
};