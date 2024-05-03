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
        if(squares[i]->getValue() == 0) {
            printSquare(i);
        }
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
    if(validGrid()) {
        safe_state = layout;
    }
}

void Grid::markupSquare(int index) {
    if(squares[index]->getValue() != 0) {
        return;
    }
    Square* target_square = squares[index];
    target_square->resetCandidates();
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

bool Grid::is_full() {
    for(int i = 0; i < 81; i++) {
        if(squares[i]->getValue() == 0) {
            return false;
        }
    }
    return true;
}

bool Grid::is_solved() {
    return is_full() && validGrid();
}

bool Grid::find_forced_nums() {
    bool made_change = false;
    for(int i = 0; i < 9; i++) {
        if(rows[i]->find_forced_number()) {
            //std::cout << "change in row " << i + 1 << std::endl;
            markupGrid();
            made_change = true;
        }
        if(cols[i]->find_forced_number()) {
            markupGrid();
            //std::cout << "change in col " << i + 1 << std::endl;
            made_change = true;
        }
        if(blocks[i]->find_forced_number()) {
            markupGrid();
            //std::cout << "change in block " << i + 1 << std::endl;
            made_change = true;
        }
        if(!validGrid()) {
            //std::cout << "Error: invalid grid" << std::endl;
            //setGrid(safe_state);
            return false;
        }
    }
    //printGrid();
    return made_change;
}

bool Grid::solve_pp() {
    //check if puzzle is already solved
    if(is_solved()) return true;
    if(!validGrid()) return false;
    while(find_forced_nums()) {
        if(is_solved()) {
            //std::cout << "The puzzle was solved. Printing grid: " << std::endl;
            //printGrid();
            return true;
        }
    }
    if(!validGrid()) {
        //std::cout << "forced contradiction" << std::endl;
        //printGrid();
        return false;
    }
    if(guess()) {
        //std::cout << "The puzzle was solved. Printing grid: " << std::endl;
        //printGrid();
        return true;
    }
    //std::cout << "Could not solve puzzle." << std::endl;
    return false;
}

std::string Grid::getSafeState() {
    return safe_state;
}

void Grid::setSafeState(std::string safe) {
    safe_state = safe;
}

//returns true if leads to solution, false if leads to invalid grid
bool Grid::guess() {
    //std::cout << "calling guess..." << std::endl;
    if(is_solved()) {
        return true;
    }
    for(int i = 0; i < 81; i++) {
        if(squares[i]->getValue() != 0) {
            continue;
        }
        //std::cout << "square at index " << i << " has " << squares[i]->num_candidates() << " candidates" << std::endl;
        int k = 1;
        while(k < squares[i]->num_candidates()) {
            if(!squares[i]->guess_kth_highest(k)) return false;
            if(solve_pp()) {               
                return true;
            }
            else {
                //std::cout << "reverting..." << std::endl;
                //printGrid();
                setGrid(safe_state);
                markupGrid();
                k++;
            }
        }
        //only one option left
        //std::cout << "square " << i << " is determined" << std::endl;
        squares[i]->guess_kth_highest(k);
        safe_state = readGrid();
        markupGrid();
    }
    return false;
}

void Grid::guessSquare(int index) {
    squares[index]->guess_highest();
}

void Grid::guessSquareKth(int index, int k) {
    squares[index]->guess_kth_highest(k);
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
        Square* new_square = new Square(i);
        squares[i] = new_square;
        rows[i / 9]->set_square(i % 9, new_square);
        cols[i % 9]->set_square(i / 9, new_square);
        int block_num = 3 * ((i / 9) / 3) + (i % 9) / 3;
        int index = (3 * (((i / 9)) % 3)) + (i % 9) % 3;
        blocks[block_num]->set_square(index, new_square);
    }
    safe_state = readGrid();
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
                new_square = new Square(i, temp);
            }
            else {
                new_square = new Square(i);
            }
            squares[i] = new_square;
            rows[i / 9]->set_square(i % 9, new_square);
            cols[i % 9]->set_square(i / 9, new_square);
            int block_num = 3 * ((i / 9) / 3) + (i % 9) / 3;
            int index = (3 * (((i / 9)) % 3)) + (i % 9) % 3;
            blocks[block_num]->set_square(index, new_square);
        }
    }
    safe_state = setup;
}

Grid::~Grid() {
}