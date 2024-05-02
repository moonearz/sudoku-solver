#include "square.h"

int Square::getValue() {
    return this->value;
}

int Square::getCandidates() {
    return this->candidates;
}

int Square::getIndex() {
    return this->index;
}

void Square::setValue(int _value) {
    this->value = _value;
    if(_value != 0) {
        this->candidates = 0;
    }
}

void Square::resetSquare() {
    this->value = EMPTY;
    this->candidates = 511;
}

void Square::resetCandidates() {
    this->candidates = 511;
}

void Square::printCandidates() {
    std::cout << "This square's candidates are: ";
    for(int i = 0; i < 9; i++) {
        if(((1 << i) & candidates) != 0) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << "# of candidates: " << num_candidates();
    std::cout << std::endl;
}

void Square::removeCandidate(int _candidate) {
    if(_candidate < 1 || _candidate > 9) {
        return;
    }
    int mask = 511 - (1 << (_candidate - 1));
    this->candidates &= mask;
}

int Square::highest_candidate() {
    if(this->candidates == 0) {
        return 0;
    }
    int highest_candidate = 1;
    int base = 1;
    while(this->candidates > base) {
        base *= 2;
        base++;
        highest_candidate++;
    }
    return highest_candidate;
}

int Square::num_candidates() {
    int temp = this->candidates;
    int count = 0;
    while(temp > 0) {
        if(temp % 2 == 1) count++;
        temp = temp >> 1;
    }
    return count;
}

bool Square::guess_highest() {
    if(this->value != 0) {
        return false;
    }
    if(this->candidates == 0) {
        return false;
    }
    //std::cout << "guessing square " << this->index << "'s value as " << this->highest_candidate() << std::endl;
    this->setValue(highest_candidate());
    return true;
}

//like guess highest, but kth highest
bool Square::guess_kth_highest(int k) {
    if(this->value != 0) {
        return false;
    }
    if(this->candidates == 0) return false;
    int counter = 1;
    while(counter < k) {
        if(this->candidates == 0) {
            return false;
        }
        this->removeCandidate(highest_candidate());
        counter++;
    }
    std::cout << "guessing square " << this->index << "'s value as " << this->highest_candidate() << std::endl;
    this->setValue(highest_candidate());
    return true;
}

Square::Square(int _index) {
    this->value = EMPTY;
    this->candidates = 511;
    this->index = _index;
}

Square::Square(int _index, int _value) {
    this->value = _value;
    this->candidates = 0;
    this->index = _index;
}

