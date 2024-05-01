#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "square.h"

class Grid {
    std::vector<Square*> squares;

    public:
        void printGrid();
        //get input from console to set grid
        std::string getGrid();
        //set grid from input string
        void setGrid(std::string layout);

        //constructors/destructor
        Grid();
        Grid(std::string setup);
        ~Grid();

};