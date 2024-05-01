#include "group.h"

Group::Group() {
    squares.reserve(9);
    for(int i = 0; i < 9; i++) {
        squares[i] = nullptr;
    }
}