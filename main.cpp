#include <iostream>
#include <cstdlib>
#include "square.h"

int main() {
    Square test = Square(3);
    Square empty = Square();
    empty.printCandidates();
    empty.removeCandidate(6);
    empty.printCandidates();
    empty.resetSquare();
    empty.printCandidates();
    return 0;
}