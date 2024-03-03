#include "grid.h"

void Grid::printGrid() {
    std::cout << " --- --- --- --- --- --- --- --- ---" << std::endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << "| 0 ";
        }
        std::cout << "|" << std::endl;
        std::cout <<  " --- --- --- --- --- --- --- --- ---" << std::endl;
    }
    std::cout << std::endl;
}

Grid::Grid() {

}