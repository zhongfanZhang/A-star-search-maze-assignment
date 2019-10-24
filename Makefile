CPPFLAGS: -std=c++11

all: robotplanner

robotplanner: main.o a_star.o maze.o
	g++ -o robotplanner main.o a_star.o maze.o

main.o: main.cpp a_star.h maze.h node.h
	g++ -std=c++11 -c main.cpp

a_star.o: a_star.cpp a_star.h
	g++ -c a_star.cpp

maze.o: maze.cpp maze.h
	g++ -c maze.cpp
