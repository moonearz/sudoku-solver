#include <iostream>
#include <cstdlib>
#include "square.h"
#include "grid.h"

int main() {
    Grid test = Grid();
    test.printGrid();
    std::string new_grid = test.getGrid();
    test.setGrid(new_grid);
    test.printGrid();
    return 0;
}