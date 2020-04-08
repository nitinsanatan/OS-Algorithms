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
					{ 1, 3, 5, 6}, 
					{ 0, 6, 5, 2 }, 
					{ 0, 6, 5, 6 } }; 

	int avail[4] = { 1, 5, 2, 0 }; // Available Resources
	
	int need[a][b]; //finding need matrix
	int i,j,k;
	for (i = 0; i < a; i++) { 
		for (j = 0; j < b; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	}
	// Make all process unfinished 
	int state[a] ; 
	for (k = 0; k < a; k++) { 
		state[k] = 0; 
	}

	// Make a copy of available resources 
	int work[b]; 
	for (i = 0; i < b ; i++) {
		work[i] = available[i]; 
	}

	// Repeat while all processes are not finished  
	int loopc=0;
	while (loopc < a) 
	{ 
		/* to find process which is unfinished
		   and current work is greater than need */
		int p,flag = 0; 
		for (p = 0; p < a; p++) 
		{ 
			// Check whether process is finished or not
			if (state[p] == 0) 
			{ 
				// Check if need<=work. 
				int j,k; 
				for (j = 0; j < b; j++) 
					if (need[p][j] > work[j]) 
						break; 

				// if state is unfinished and work>=need 
				if (j == b) 
				{ 
					//freeing the resources 
					for (k = 0 ; k < b ; k++) {
						work[k]+=alloc[p][k]; 
					}
					
					loopc++;
					// Mark this process finished 
					state[p] = 1; 
					flag = 1;
			
				} 
			} 
		} 

		// if we could not find a next process in safe sequence.
		
		if (flag == 0) 
		{ 
			printf("System is not in safe state");
			return 0;  
		} 
	} 

	// If system is in safe state
	printf("System is in safe state" );  
	return 0; 
}
