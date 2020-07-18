#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("program must have 2 arguments\n");
		return 3;
	}
	char * fileName = argv[1];
	int size = atoi(argv[2]);
	char* c = (char*) malloc(size*sizeof(char));;
	FILE * file = fopen(fileName, "r");
	if (file == NULL) {
		printf("can't open file\n");
		return 1;
	}
	
	
	int i = 0;
	while(i < size -1 && !feof(file)){
		c[i] = getc(file);
		++i;
	}
	c[i] = '\0';
	
	printf("file content:\n%s", c);
	
	free(c);
	return 0;
	
}