#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

struct Node{

	
	std::vector<char> path;
	//contains the directions to get here
	
	double value;
	//dist to current node can be determined
	//by doing directions.size(), then the
	//heuristic added to the value
	
	int x, y;
	//x and y coordinates on the map

};

#endif
