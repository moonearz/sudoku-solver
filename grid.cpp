#include "grid.h"

void Grid::printGrid() {
    std::cout << " --- --- --- --- --- --- --- --- ---" << std::endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << "| ";
            if(squares[9 * i + j]->getValue() > 0) {
                std::cout << squares[9 * i + j]->getValue(); 
            }
            else {
                std::cout << " ";
            }
            std::cout <<  " ";
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

void Grid::printSquare(int index) {
     std::cout << "Square " << index << "-- ";
     squares[index]->printCandidates();
}
void Grid::printSquareCandidates() {
    for(int i = 0; i < 81; i++) {
        printSquare(i);
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

std::string Grid::readGrid() {
    std::string output = "";
    for(int i = 0; i < 81; i++) {
        output += std::to_string(squares[i]->getValue());
    }
    return output;
}

void Grid::setGrid(std::string layout) {
    for(int i = 0; i < layout.size(); i++) {
        squares[i]->setValue(int(layout[i]) - 48);
    }
}

void Grid::markupSquare(int index) {
    if(squares[index]->getValue() != 0) {
        return;
    }
    Square* target_square = squares[index];
    int row_number = index / 9;
    int col_number = index % 9;
    int block_number = 3 * ((index / 9) / 3) + (index % 9) / 3;
    for(int i = 0; i < 9; i++) { 
        target_square->removeCandidate(rows[row_number]->get_square(i)->getValue());
        target_square->removeCandidate(cols[col_number]->get_square(i)->getValue());
        target_square->removeCandidate(blocks[block_number]->get_square(i)->getValue());
    }
}

void Grid::markupGrid() {
    for(int i = 0; i < 81; i++) {
        markupSquare(i);
    }
}

bool Grid::validRows() {
    for(int i = 0; i < 9; i++) {
        if(!rows[i]->valid_group()) {
            //std::cout << "Row " << i + 1 << " is not valid!" << std::endl;
            return false;
        }
    }
    return true;
}

bool Grid::validCols() {
    for(int i = 0; i < 9; i++) {
        if(!cols[i]->valid_group()) {
            //std::cout << "Column " << i + 1<< " is not valid!" << std::endl;
            return false;
        }
    }
    return true;
}

bool Grid::validBlocks() {
    for(int i = 0; i < 9; i++) {
        if(!blocks[i]->valid_group()) {
            //std::cout << "Block " << i + 1 << " is not valid!" << std::endl;
            return false;
        }
    }
    return true;
}

bool Grid::validGrid() {
    return validRows() && validCols() && validBlocks();
}

bool Grid::gridMatch(std::string target) {
    if(target.size() != 81) {
        return false;
    }
    for(int i = 0; i < target.size(); i++) {
        if('0' + squares[i]->getValue() != target[i]) {
            return false;
        }
    }
    return true;
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
        cols[i % 9]->set_square(i / 9, new_square);
        int block_num = 3 * ((i / 9) / 3) + (i % 9) / 3;
        int index = (3 * (((i / 9)) % 3)) + (i % 9) % 3;
        blocks[block_num]->set_square(index, new_square);
    }
}

Grid::Grid(std::string setup) {
    squares.reserve(81);
    if(setup.size() != 81) {
        Grid();
    }
    else {
        for(int i = 0; i < 9; i++) {
            Group* new_row = new Group();
            Group* new_col = new Group();
            Group* new_block = new Group();
            rows.push_back(new_row);
            cols.push_back(new_col);
            blocks.push_back(new_block);
        }
        for(int i = 0; i < setup.size(); i++) {
            Square* new_square = nullptr;
            if(setup.at(i) <= '9' && setup.at(i) >= '1') {
                int temp = setup.at(i) - '0';
                new_square = new Square(temp);
            }
            else {
                new_square = new Square();
            }
            squares[i] = new_square;
            rows[i / 9]->set_square(i % 9, new_square);
            cols[i % 9]->set_square(i / 9, new_square);
            int block_num = 3 * ((i / 9) / 3) + (i % 9) / 3;
            int index = (3 * (((i / 9)) % 3)) + (i % 9) % 3;
            blocks[block_num]->set_square(index, new_square);
        }
    }
}

Grid::~Grid() {
}