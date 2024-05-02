#include "group.h"

Group::Group() {
    squares.reserve(9);
    for(int i = 0; i < 9; i++) {
        squares[i] = nullptr;
    }
}

void Group::print_group() {
    for(int i = 0; i < 9; i++) {
        if(squares[i] == nullptr) {
            std::cout << "nullptr ";
        }
        else {
            std::cout << squares[i]->getValue() << " ";
        }
    }
    std::cout << std::endl;
}

bool Group::valid_group() {
    std::vector<int> unused = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 0; i < 9; i++) {
        if(squares[i]->getValue() == 0) {
            continue;
        }
        bool flag = true;
        for(int j = 0; j < unused.size(); j++) {
            if(squares[i]->getValue() == unused[j]) {
                unused.erase(unused.begin() + j);
                flag = false;
                break;
            }
        }
        if(flag) return false;
    }
    return true;
}

void Group::set_square(int index, Square* square) {
    squares[index] = square;
}

Square* Group::get_square(int index) {
    return squares[index];
}

bool Group::find_forced_number() {
    //idea: bitwise OR, then XOR together all candidates and if there is a single number left, that is a forced number
    bool made_change = false;
    std::vector<int> pows_of_two = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    for(int i = 0; i < 9; i++) {
        int target_candidates = squares[i]->getCandidates();
        if(target_candidates == 0) {
            continue;
        }
        //check if there is only one candidate
        bool one_candidate = false;
        for(int j = 0; j < 9; j++) {
            if(target_candidates == pows_of_two[j]) {
                std::cout << "only-- setting square " << squares[i]->getIndex() << "'s value to: " << j + 1 << std::endl;
                squares[i]->setValue(j + 1);
                made_change = true;
                one_candidate = true;
                break;
            }
        }
        if(one_candidate) continue;
        for(int j = 0; j < 9; j++) {
            if(i == j) {
                continue;
            }
            if(squares[j]->getValue() == 0) {
                target_candidates |= squares[j]->getCandidates();
                target_candidates ^= squares[j]->getCandidates();
            }
            else {
                target_candidates &= ~(1 << (squares[j]->getValue() - 1));
            }
        }
        //check new candidate value
        for(int j = 0; j < 9; j++) {
            if(target_candidates == pows_of_two[j]) {
                std::cout << "after operation-- setting square " << squares[i]->getIndex() <<  "'s value to: " << j + 1 << std::endl;
                squares[i]->setValue(j + 1);
                made_change = true;
                break;
            }
        }
    }
    return made_change;
}