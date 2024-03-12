#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "square.h"

class Grid {
    std::vector<Square*> squares;

    public:
        void printGrid();
        void setGrid();

        //constructors
        Grid();
        Grid(std::string setup);

};