#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "maze.h"
#include "a_star.h"
#include "node.h"
using namespace std;

int main(int argc, char* argv[]){

	Maze m(argv[1], argv[2], argv[3], argv[4], argv[5]);
	A_star a(&m);
	
	while( a.explore() ){
		a.sort_fringe();
	}

	vector<char> res = a.return_path();
	
	//print results
	a.print_info();
	for( int i = 0; i < res.size(); i++ ){
		cout << res[i] << " ";
	}
	cout << endl;
}
