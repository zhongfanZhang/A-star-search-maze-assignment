#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>

class Maze{

	private:

		std::vector< std::vector<int> > map;
		int maze_x;
		int maze_y;
		int start_x;
		int start_y;
		int end_x;
		int end_y;

	public:

		Maze( std::string, char*, char*, char*, char* );
		//constructor, reads file and stores grid in map,
		//stores start and end positions
		
		std::vector<int> check_directions( int, int );
		//returns a length 4 vector with available directions,
		//e.g. [1 0 1 0] means up and left are possible paths
		//[U D L R]

		std::vector<int> pass_coords();
		//returns the start and end positions in a vector

};

#endif
