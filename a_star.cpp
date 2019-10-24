#include "a_star.h"
using namespace std;

A_star::A_star(Maze* mp){

    //storing values
    m = mp;
	
	vector<int> t = m -> pass_coords();
	start_x = t[0];
	start_y = t[1];
	end_x = t[2];
	end_y = t[3];

	nodes_visited = 0;

    //setting up starting node
    Node* temp = new Node;
    temp -> x = start_x;
    temp -> y = start_y;
    temp -> value = sqrt( pow((end_x-start_x),2) + pow((end_y-start_y),2) ); 
    
    //add starting node to the fringe
    fringe.push_back(temp);
    node_dist.push_back(temp -> value );
}

Node* A_star::makeNode( int ix, int iy, double val, vector<char> pa ){

    Node* temp = new Node;
    temp -> x = ix;
    temp -> y = iy;
    temp -> value = val + sqrt( pow((end_x-ix),2) + pow((end_y-iy),2) );
    temp -> path = pa;

    return temp;
}

int A_star::explore(){
/*  explore the frontmost node in the fringe and add
    its children to the fringe. USE THE get_directions from
    maze.h, add heuristic to the node value. 
    returns 0 if destination is found
    return 1 if else  */


    //check for destination
    if( fringe[0] -> x == end_x && fringe[0] -> y == end_y ){
        return 0;
    }else if( fringe.size() == 0 ){
		cout << nodes_visited << " 0\n";
		return 0;
	}

    //make temp values for ease of access
    int fx = fringe[0] -> x;
    int fy = fringe[0] -> y;
    double fv = fringe[0] -> value;
    vector<char> fp = fringe[0] -> path; 

//	cout << "fx = " << fx << ", fy = " << fy << ", fv = " << fv << endl;

    //check directions and make nodes of available directions
    vector<int> ad = m -> check_directions(fx,fy);

	//UP path
    if( ad[0] == 1 ){
        Node* temp = makeNode(fx,fy-1,fp.size(),fp);
        temp -> path.push_back('U');
        fringe.push_back(temp);
        node_dist.push_back(temp -> value);
		nodes_visited++;
    }
    //DOWN path
    if( ad[1] == 1 ){
        Node* temp = makeNode(fx,fy+1,fp.size(),fp);
        temp -> path.push_back('D');
        fringe.push_back(temp);
        node_dist.push_back(temp -> value);
		nodes_visited++;
    }
    //LEFT path
    if( ad[2] == 1 ){
        Node* temp = makeNode(fx-1,fy,fp.size(),fp);
        temp -> path.push_back('L');
        fringe.push_back(temp);
        node_dist.push_back(temp -> value);
		nodes_visited++;
    }
    //RIGHT path
    if( ad[3] == 1){
        Node* temp = makeNode(fx+1,fy,fp.size(),fp);
        temp -> path.push_back('R');
        fringe.push_back(temp);
        node_dist.push_back(temp -> value);
		nodes_visited++;
    }

/*
	cout << "distances = ";
	for(int i = 0; i < fringe.size(); i++ ){
		cout << node_dist[i] << " ";
	}
	cout << endl;

	cout << "nodes = ";
	for(int i = 0; i < fringe.size(); i++ ){
		for(int j = 0; j < fringe[i] -> path.size(); j++ ){
			cout << fringe[i] -> path[j];
		}
		cout << " = " << fringe[i] -> value << ", ";
	}
	cout << endl;
*/	
	fringe.erase(fringe.begin());
	node_dist.erase(node_dist.begin());
    return 1;
}

void A_star::sort_fringe(){
//use std::sort to sort the node value int vector.
//then match up the distances with their nodes and make a
//new node vector
	

    //sort nodes by distance
    sort(node_dist.begin(), node_dist.end());
	
    //put sorted nodes into temp
    vector<Node*> temp;

    int iter = fringe.size();
    int index = 0;

	//cout << "Kappa\n";
    //search the fringe vector
    while( temp.size() < iter ){
        
        double dist = node_dist[index];
        //search the fringe
        for( int i = 0 ; i < fringe.size(); i++ ){
            if( fringe[i] -> value == dist ){
                temp.push_back(fringe[i]);
                fringe.erase(fringe.begin()+i);
                break;
            }
        }
		//cout << "index = " << index << endl;
        index++;
    }

	fringe = temp;
/*
	cout << "nodes = ";
	for(int i = 0; i < fringe.size(); i++ ){
		for(int j = 0; j < fringe[i] -> path.size(); j++ ){
			cout << fringe[i] -> path[j];
		}
		cout << " = " << fringe[i] -> value << ", ";
	}
	cout << endl;
*/

}

vector<char> A_star::return_path(){
//get the path string from the first node in the fringe
//and return it
    return fringe[0] -> path;
}

void A_star::print_info(){
	cout << nodes_visited << " " << fringe[0] -> path.size() << endl;
}
