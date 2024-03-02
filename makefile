main: main.o square.o
	g++ -o main main.o square.o

main.o: main.cpp square.h
	g++ -c main.cpp

square.o: square.h