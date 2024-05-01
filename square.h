#pragma once

#include <iostream>

#define EMPTY 0

class Square {
        int value;
        //111111111 9 bits for each possible value
        int candidates;
        int index;
    public:
        int getValue();
        int getCandidates();
        int getIndex();
        void setValue(int _value);
        void resetSquare();
        void printCandidates();
        void removeCandidate(int _candidate);
        //constructors
        Square(int _index);
        Square(int _index, int _value);;
};