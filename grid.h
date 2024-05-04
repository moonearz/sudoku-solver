#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "square.h"
#include "group.h"

class Grid {
    std::vector<Square*> squares;
    std::vector<Group*> rows;
    std::vector<Group*> cols;
    std::vector<Group*> blocks;
    std::string safe_state;

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

        //solve with pencil-and-paper algorithm ->requires backtracking in some cases
        bool is_full();
        bool is_solved();
        bool find_forced_nums();
        bool solve_pp();

        //backtracking
        std::string getSafeState();
        void setSafeState(std::string safe);
        bool guess();
        void guessSquare(int index);
        void guessSquareKth(int index, int k);

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