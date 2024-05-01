#include <iostream>
#include <cstdlib>
#include "square.h"
#include "grid.h"

int main() {
    //TEST GRIDS
    std::string test_rows = "123456789123456789123456789123456789123456789123456789123456789123456789123456789";
    std::string test_blocks = "123456789234567891345678912456789123567891234678912345789123456891234567912345678";
    std::string test_valid = "124567893378294516659831742987123465231456978546789321863972154495618237712345689";
    std::string unsolved_shortz = "039500000000800070000010904100400003000000000007000860006708200010090005000001008";




    Grid test = Grid(unsolved_shortz);
    test.printGrid();
    test.setGrid(test_valid);
    test.printGrid();
    return 0;
}