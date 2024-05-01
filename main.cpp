#include <iostream>
#include <cstdlib>
#include "square.h"
#include "grid.h"

int main() {
    //TEST GRIDS
    std::string test_1 = "123456789123456789123456789123456789123456789123456789123456789123456789123456789";
    std::string test_2 = "123456789234567891345678912456789123567891234678912345789123456891234567912345678";




    Grid test = Grid(test_1);
    test.printRows();
    test.printCols();
    test.printBlocks();
    test.printGrid();
    return 0;
}