#include<stdio.h>
#include<unistd.h>

int main() { 

	int a = 5; // Number of processes 
	int b = 4; // Number of resources
	
	int alloc[5][4] = { { 0, 0, 1, 2 }, // Allocation Matrix 
						{ 1, 0, 0, 0 }, 
						{ 1, 3, 5, 4 },  
						{ 0, 6, 3, 2 }, 
						{ 0, 0, 1, 4 } }; 

	int max[5][4] = { { 0, 0, 1, 2}, //max matrix
					{ 3, 7, 5,0 },  
					{ 2, 3, 5, 6}, 
					{ 0, 6, 5, 2 }, 
					{ 0, 6, 5, 6 } }; 

	int avail[4] = { 1, 5, 2, 0 }; // Available Resources
	
	int need[a][b]; //finding need matrix
	int i,j,k;
	for (i = 0; i < a; i++) { 
		for (j = 0; j < b; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	}
