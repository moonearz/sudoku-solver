#include <iostream>
#include <cstdlib>
#include "square.h"

int main() {
    Square test = Square(3);
    Square empty = Square();
    std::cout << "this square's candidates are: ";
    empty.printCandidates();
    empty.removeCandidate(3);
    std::cout << "this square's candidates are now: ";
    empty.printCandidates();
    return 0;
}