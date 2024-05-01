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
        void printSquare(int index);
        void printSquareCandidates();
        std::string readGrid();
        //get input from console to set grid
        std::string getGrid();
        //set grid from input string
        void setGrid(std::string layout);

        //markup functions
        void markupSquare(int index);
        void markupGrid();

        //solve with pencil-and-paper algorithm
        bool is_solved();
        bool find_forced_nums();
        void solve_pp();

        //valid grid checkers
        bool validRows();
        bool validCols();
        bool validBlocks();
        bool validGrid();

        //compare grid to string
        bool gridMatch(std::string target);

        //constructors/destructor
        Grid();
        Grid(std::string setup);
        ~Grid();

};