#include "square.h"

int Square::getValue() {
    return this->value;
}

int Square::getCandidates() {
    return this->candidates;
}

void Square::setValue(int _value) {
    this->value = _value;
}

void Square::resetSquare() {
    this->value = EMPTY;
    this->candidates = 0x1ff;
}

void Square::printCandidates() {
    for(int i = 0; i < 9; i++) {
        if(((1 << i) & candidates) != 0) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl;
}

void Square::removeCandidate(int _candidate) {
    if(_candidate < 1 || _candidate > 9) {
        return;
    }
    int mask = 511 - (1 << (_candidate - 1));
    this->candidates &= mask;
}

Square::Square() {
    this->value = EMPTY;
    this->candidates = 0x1ff;
}

Square::Square(int _value) {
    this->value = _value;
    this->candidates = 0x1ff;
}

