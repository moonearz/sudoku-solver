#pragma once

#include <vector>
#include <iostream>
#include "square.h"

class Group {
    std::vector<Square*> squares;
    
    public:
        //constructor
        Group();
        //functions
        void print_group(); 
        bool valid_group();
        void set_square(int index, Square* square);
        Square* get_square(int index);
        bool find_forced_number();
};