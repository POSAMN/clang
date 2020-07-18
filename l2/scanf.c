#include <stdio.h>

int main() {
	int i;
	int x;
	int * pi = &i;
	scanf("%d %d", pi, &x);
	
	printf("%d", i + x);
	
}