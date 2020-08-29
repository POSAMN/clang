#include <stdio.h>

int main() {
	int i = 10;
	int j;
	j = ++i;
	{
		//аналог
		i++;
		j = i;
	}
	
	
	j = i++;
	
	{
		//аналог
		j = i;
		i++;
	}
	
	
	printf("%d %d\n", i, j);
	return 0;
}