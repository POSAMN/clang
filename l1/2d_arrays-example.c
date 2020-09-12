#include <stdio.h>
#include <stdlib.h>


int main() {
	//allocate 2d_array 5*5 and fill with number 0..24
	int ** arr2d = (int**)malloc(5 * sizeof(int*));
	for (int i = 0; i < 5; i++){
		arr2d[i] = (int*)malloc(5 * sizeof(int));
		for (int j = 0; j < 5; j++){
			arr2d[i][j]	= 5 * i + j;
		}
		
	}
	
	printf("%d ,%d .%d", arr2d[4][4], arr2d[1][3], arr2d[3][1]);
	
	
	for (int i =0; i < 5; i++){
		free(arr2d[i]);
	}
	free(arr2d);
	return 0;
}
