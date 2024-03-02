#include "square.h"

int Square::getValue() {
    return this->value;
}

void Square::setValue(int _value) {
    this->value = _value;
}

Square::Square() {
    this->value = EMPTY;
    this->candidates = 0;
}

Square::Square(int _value) {
    this->value = _value;
    this->candidates = 0;
}

