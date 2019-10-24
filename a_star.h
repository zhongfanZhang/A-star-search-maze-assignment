#ifndef A_STAR_H
#define A_STAR_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "node.h"
#include "maze.h"

class A_star{

	private:

		Maze* m;

        std::vector<Node*> fringe;
        std::vector<double> node_dist;
		int start_x, start_y, end_x, end_y;

		int nodes_visited;
	
	public:

		A_star(Maze*);
		//store starting and end positions, storing maze
		//reference. create a tree
	
		Node* makeNode(int, int, double, std::vector<char>);
		
		int explore();
		//explores the best node in the fringe and adds
		//its childs to the fringe and remove the 
		//explored node from the fringe
		//returns 0 if destination is found
		//returns 1 else

		void sort_fringe();
		//sorts the fringe nodes by their values
		
		void print_info();
        std::vector<char> return_path();

};

#endif
