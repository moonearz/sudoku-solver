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

Grid::Grid() {
    //figure out how to do this in initiazliation
    squares.reserve(81);
    for(int i = 0; i < 81; i++) {
        squares[i] = new Square();
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