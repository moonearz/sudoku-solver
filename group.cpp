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