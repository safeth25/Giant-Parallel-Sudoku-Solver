#include <cmath>
#include <vector>
#include <fstream>

#include "library/Grid.hpp"

int main (int argc, char *argv[]){

    // Anzahl der Argumente überprüfen.
    if (argc != 7) {
        std::cout << "Falsche Anzahl an Argumenten. Das Programm benötigt --file, --gridsize, --algorithm_type \n";
        return 1;
    }
    bool algorithm_type;
    int gridsize;
    std::string filename;

    for (int i = 1; i < argc; i += 2) {
        // Argumente überprüfen
        if(!std::strcmp(argv[i], "--file")){
            filename = argv[i+1];
        } else if(!std::strcmp(argv[i], "--gridsize")){
            gridsize = std::stoi(argv[i+1]);
        } else if(!std::strcmp(argv[i], "--algorithm_type")){
            algorithm_type = std::stod(argv[i+1]);
        }
        else{
        std::cout << "Error. Das Programm benötigt --file, --gridsize, --algorithm_type \n";
        return 1;
        }
    }
    
    std::cout << "Filename: " << filename << std::endl;
    std::cout << "Gridsize: " << gridsize << std::endl;
    std::cout << "Algorithm Type: " << algorithm_type << std::endl;

    // Create sudoku grid NxN where N = gridsize
    Grid sudoku(gridsize);

    // Read from sudoku-file
    sudoku.readSudokuFromFile(filename);

    // Display sudoku
     sudoku.displaySudoku();

    // Write to output.txt
    sudoku.writeSudokuToFile();
}