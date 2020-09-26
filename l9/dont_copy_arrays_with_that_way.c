#include <stdio.h>
#include <stdlib.h>

int main() {
	int * arr = malloc(sizeof(int)*1100);
	arr[1] = 10;
	int * arr2 = arr;//это копия указателя
	arr2[1] = 1220;
	printf("%d\n", arr[1]);
	
	//free(arr);
	printf("%d\n", arr2[1]);
	
	
	return 0;
}