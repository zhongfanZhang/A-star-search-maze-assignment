#include "maze.h"
using namespace std;

Maze::Maze(string filename, char* a_x, char* a_y, char* b_x, char* b_y){

	//start coordinates
	start_x = atoi(a_x);
	start_y = atoi(a_y);

	//goal coordinates
	end_x = atoi(b_x);
	end_y = atoi(b_y);
	
	//file processing
	ifstream file;
	file.open(filename);
	int x,y;
	file >> x >> y;
	maze_x = x;
	maze_y = y;
	map.resize(y,vector<int>(x,0));
	for( int i = 0; i < y; i++ ){
		for( int j = 0; j < x; j++ ){
			file >> map[i][j];
		}
	}
	file.close();
}

vector<int> Maze::check_directions( int x, int y ){

	vector<int> valid_directions(4,0);
	//[U D L R]

	if( map[y][x] == 1 ){
		//cout << map[y][x];
		return valid_directions;
	}

	//Up
	if( (y-1) >= 0 && map[y-1][x] == 0 ){
		valid_directions[0] = 1;
	}

	//Down
	if( (y+1) < maze_y && map[y+1][x] == 0 ){
		valid_directions[1] = 1;
	}

	//Left
	if( (x-1) >= 0 && map[y][x-1] == 0 ){
		valid_directions[2] = 1;
	}

	//Right
	if( (x+1) < maze_x && map[y][x+1] == 0 ){
		valid_directions[3] = 1;
	}
	
	map[y][x] = 1;

	return valid_directions;
}

vector<int> Maze::pass_coords(){
	
	vector<int> temp;
	temp.push_back(start_x);
	temp.push_back(start_y);
	temp.push_back(end_x);
	temp.push_back(end_y);

	return temp;
}
