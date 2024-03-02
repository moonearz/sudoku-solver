#pragma once

#define EMPTY 0

class Square {
        int value;
        unsigned char candidates;
    public:
        int getValue();
        void setValue(int _value);
        Square();
        Square(int _value);
};