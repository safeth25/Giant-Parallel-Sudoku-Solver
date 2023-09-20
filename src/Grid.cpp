#include "library/Grid.hpp"

Grid::Grid(int N) : gridSize(N){
    grid = std::vector<std::vector<int>>(gridSize, std::vector<int>(gridSize, 0));
}

// Methode zum Anzeigen des Sudoku-Gitters
void Grid::displaySudoku() {
    int size = std::sqrt(gridSize);
    for (int i = 0; i < gridSize; i++) {
        if (i > 0 && i % size == 0) {
            if(size == 3){
                std::cout << "------+-------+------" << std::endl;
            }
            else if(size == 4){
                std::cout << "--------+---------+---------+--------\n";
            }
            else{
                std::cout << "----------+-----------+-----------+-----------+-----------\n";
            }
        }
        for (int j = 0; j < gridSize; j++) {
            if (j > 0 && j % size == 0) {
                std::cout << "| ";
            }
            if(grid[i][j] == UNASSIGNED){
                std::cout << "*" << ' ';
            }
            else{
                std::cout << grid[i][j] << ' ';
            } 
        }
        std::cout << std::endl;
    }
}

int Grid::getCellValueAt(int row, int column){
    return grid[row][column];
}

void Grid::readSudokuFromFile(std::string filename){
    std::ifstream inputFile (filename);
    if(!inputFile.is_open()){
        std::cout << "Error opening " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            std::string cellValue;
            if (inputFile >> cellValue) {
                grid[i][j] = std::stoi(cellValue);
            }
        }
    }
    inputFile.close();
}

void Grid::writeSudokuToFile(){
    std::string filename = "output.txt";
    //Test ob der zu beschreibende file geöffnet werden konnte.
    std::fstream file_out;
    file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()) {
        std::cout << "Failed to open " << filename << '\n';
        exit(EXIT_FAILURE);
    }
    else{
        for(int i = 0; i < gridSize; i++){
            for(int k = 0; k < gridSize; k++){
                file_out << grid[i][k] << " ";
            }
            file_out << std::endl;
        }
    }
}

void Grid::setCellValueAt(int value, int row, int column){
    grid[row][column] =  value;
}
