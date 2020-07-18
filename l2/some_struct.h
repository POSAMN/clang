#include <stdio.h>
#include <stdlib.h>


typedef struct data {
	int num;
	const int* ints;
	int ints_size;
	double volume;
} data_t;

void printData(const data_t* d);