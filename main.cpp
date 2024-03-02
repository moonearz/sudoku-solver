#include <iostream>
#include <cstdlib>
#include "square.h"

int main() {
    Square test = Square(3);
    std::cout << "this square's value is: " << test.getValue() << std::endl;
    return 0;
}