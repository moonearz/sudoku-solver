main: main.o square.o grid.o
	g++ -o main main.o square.o grid.o

main.o: main.cpp square.h grid.h
	g++ -c main.cpp

grid.o: grid.cpp square.h

square.o: square.h
