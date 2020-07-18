#include <stdio.h>
#include <stdlib.h>


int main() {
	//allocate int array with size 1000
	int size = 1000;
	int * arr = (int *) malloc(size * sizeof(int));
	for (int i = 0; i < size; i++){
		arr[i] = i*i;
	}
	
	for (int i = 0; i < 100; i++) {
		printf("%d\n", arr[i]);
	}
	int * p  = arr + 10;
	free(arr);
	return 0;
}