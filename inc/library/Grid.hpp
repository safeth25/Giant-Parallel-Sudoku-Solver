#include <vector>
#include <iostream>
#include <fstream>

#pragma once

class Grid{

    private:
    // // Die Größe des Sudoku-Gitters (z.B., 9 für ein 9x9-Gitter)
    int gridSize;

    // Die Matrix zur Speicherung der Sudoku-Zahlen
    std::vector<std::vector<int>> grid;

    public:
    Grid(int gridSize);

    void displaySudoku();

    void readSudokuFromFile(std::string filename);

    void writeSudokuToFile();
};