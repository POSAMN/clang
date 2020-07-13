#include <stdio.h>
#include <stdlib.h>


int main() {
	//allocate 2d_array 200*100
	int rows = 200;
	int cols = 100;
	int ** arr2d = (int **) malloc(rows * sizeof(int*));
	
	for (int i = 0; i < rows; ++i){
		arr2d[i] = (int *) malloc(100 * sizeof(int));
	}
	
	/// some work with 2d_array
	
	
	for (int i = ; i < rows; ++i){ 
		free(arr2d[i]);
	}
	free(arr2d);
	
	return 0;
}