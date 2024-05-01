#include "grid.h"

void Grid::printGrid() {
    std::cout << " --- --- --- --- --- --- --- --- ---" << std::endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << "| " << squares[9 * i + j]->getValue() <<  " ";
        }
        std::cout << "|" << std::endl;
        std::cout <<  " --- --- --- --- --- --- --- --- ---" << std::endl;
    }
    std::cout << std::endl;
}

void Grid::printRows(){
    for(int i = 0; i < 9; i++) {
        std::cout << "Row " << i + 1 << ":" << std::endl;
        rows[i]->print_group();
    }
}

void Grid::printCols(){
    for(int i = 0; i < 9; i++) {
        std::cout << "Column " << i + 1 << ":" << std::endl;
        cols[i]->print_group();
    }
}

void Grid::printBlocks(){
    for(int i = 0; i < 9; i++) {
        std::cout << "Block " << i + 1 << ":" << std::endl;
        blocks[i]->print_group();
    }
}

std::string Grid::getGrid() {
    std::string input;
    std::string setup;
    for(int i = 0; i < 9; i++) {
        std::cout << "Enter in the " << (i + 1) << "th row: ";
        std::cin >> input;
        setup += input;
    }
    return setup;
}

void Grid::setGrid(std::string input) {
    for(int i = 0; i < input.size(); i++) {
        squares[i]->setValue(int(input[i]) - 48);
    }
}

bool Grid::validRows() {
    for(int i = 0; i < 9; i++) {
        if(!rows[i]->valid_group()) {
            std::cout << "Row " << i + 1 << " is not valid!" << std::endl;
            return false;
        }
    }
    std::cout << "The rows are all good!" << std::endl;
    return true;
}

bool Grid::validCols() {
    for(int i = 0; i < 9; i++) {
        if(!cols[i]->valid_group()) {
            std::cout << "Column " << i + 1<< " is not valid!" << std::endl;
            return false;
        }
    }
    return true;
}

bool Grid::validBlocks() {
    for(int i = 0; i < 9; i++) {
        if(!rows[i]->valid_group()) {
            std::cout << "Block " << i + 1 << " is not valid!" << std::endl;
            return false;
        }
    }
    return true;
}

bool Grid::validGrid() {
    return validRows() && validCols() && validBlocks();
}

Grid::Grid() {
    //figure out how to do this in initiazliation
    squares.reserve(81);
    for(int i = 0; i < 9; i++) {
        Group* new_row = new Group();
        Group* new_col = new Group();
        Group* new_block = new Group();
        rows.push_back(new_row);
        cols.push_back(new_col);
        blocks.push_back(new_block);
    }
    for(int i = 0; i < 81; i++) {
        Square* new_square = new Square();
        squares[i] = new_square;
        rows[i / 9]->set_square(i % 9, new_square);
    }
}

Grid::Grid(std::string setup) {
    squares.reserve(81);
    if(setup.size() != 81) {
        Grid();
    }
    else {
        for(int i = 0; i < setup.size(); i++) {
            if(setup.at(i) <= '9' && setup.at(i) >= '1') {
                int temp = setup.at(i) - '1';
                squares[i] = new Square(temp);
            }
            else {
                squares[i] = new Square();
            }
        }
    }
}

Grid::~Grid() {
    for(int i = 0; i < squares.size(); i++) {
        delete squares[i];
        std::cout << "square " << i << " deleted." << std::endl;
    }
    std::cout << "destructor called" << std::endl;
}