Assignment1 - readme.txt



How To Run "robotplanner"
	To run robotplanner, a map file, starting and ending coordinates are required. Below is the general command:
		
		./robotplanner "map file name" "starting x-coord" "starting y-coord" "end x-coord" "end y-coord"
	
	Valid map files contains only numbers, the first line specifies the amount of columns and rows that the map has respectively. 
	For the rest of the lines, a "1" represents non-traversible terrain while a "0" is traversible terrain. 
	An example of a valid map is shown below:
	
	5 5
	1 0 1 0 0
	1 0 0 1 0
	0 1 0 1 0
	0 1 0 1 0
	0 0 0 0 0

	If robotplanner is run with the command:

		./robotplanner mapfile 1 0 3 0

	The output should be:
		
		15 12	
		D R D D D R R U U U U L

	The first line of the output shows the amount of nodes searched and the shortest path length respectively.
	The second line of the output shows the shortest path in directions U(up) D(down) L(left) R(right).
	If no valid path is found the output should show:

		N 0
		X
	
	Where N is the number of nodes searched. The X indicates that there is no path possible.
