#include <stdio.h>
#include <stdlib.h>

void incrementByTwo(int * x) {
	*x += 2;
}

void incrementValByTwo(int x) {
	x +=2;
}

int main() {
	int x = 42;
	int y = 42;
	
	incrementByTwo(&x);
	incrementValByTwo(y);
	
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	
	return 0;
}