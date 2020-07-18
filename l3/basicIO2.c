#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("program must have 2 arguments\n");
		return 3;
	}
	char * inputFileName = argv[1];
	char * outputFileName = argv[2];
	FILE * input = fopen(inputFileName, "r");
	if (input == NULL) {
		printf("cant open file %s", inputFileName);
		return 1;
	}
	
	FILE * output = fopen(outputFileName, "w");
	if (output == NULL) {
		printf("cant open file %s", outputFileName);
	}
	int num = 0;
	int sum = 0;
	while (!feof(input)) {
		fscanf(input, "%d", &num);
		sum += num;
		fprintf(output, "%d;\n", sum);
	}
	fclose(input);
	fclose(output);
	return 0;
	
}