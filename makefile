CXXFLAGS =-std=c++11

main: main.o square.o grid.o group.o
	g++ -o main main.o square.o grid.o group.o

main.o: main.cpp square.h grid.h group.h
	g++ -c main.cpp

grid.o: grid.cpp square.h group.h

group.o: group.cpp square.h

square.o: square.h
