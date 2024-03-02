#pragma once

#include <iostream>
#include <bitset>

#define EMPTY 0

class Square {
        int value;
        //111111111 9 bits for each possible value
        int candidates;
    public:
        int getValue();
        int getCandidates();
        void setValue(int _value);
        void resetSquare();
        void printCandidates();
        void removeCandidate(int _candidate);
        //constructors
        Square();
        Square(int _value);;
};