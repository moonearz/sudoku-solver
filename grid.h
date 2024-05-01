#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "square.h"
#include "group.h"

class Grid {
    std::vector<Square*> squares;
    std::vector<Group*> rows;
    std::vector<Group*> cols;
    std::vector<Group*> blocks;

    public:
        void printGrid();
        void printRows();
        void printCols();
        void printBlocks();
        //get input from console to set grid
        std::string getGrid();
        //set grid from input string
        void setGrid(std::string layout);

        //valid grid checkers
        bool validRows();
        bool validCols();
        bool validBlocks();
        bool validGrid();

        //constructors/destructor
        Grid();
        Grid(std::string setup);
        ~Grid();

};