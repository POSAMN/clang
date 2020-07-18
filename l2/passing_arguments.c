#include <stdio.h>
#include <stdlib.h>

const char * template = "num = %d; text = %s; volume = %f; ints[0] = %d\n";

typedef struct data {
	int num;
	char* text;
	int text_size;
	const int* ints;
	double volume;
} data_t;

void printData(data_t d) {
	d.num += 2;
	//d.ints[0] += 14;
	printf(template, d.num, d.text, d.volume, d.ints[0]);
}

void printDataByPointer(data_t* pd) {
	pd->num += 3;
	printf(template, pd->num, pd->text, pd->volume, pd->ints[0]);
}


void printDataByConstPointer(const data_t* pd) {
	
	printf(template, pd->num, pd->text, pd->volume, pd->ints[0]);
}



int main() {
	char text[] = {'t', 'e', 's', 't', 0};
	int * ints = (int*) malloc(5*sizeof(int));
	ints[0] = 10;
	ints[1] = 12;
	data_t example = {42, text , 4, ints, 2.1};
	printData(example);
	printData(example);
	printDataByPointer(&example);
	printDataByConstPointer(&example);
	
	if (template[47] == 0) {
		printf("48 == 0");
	}
	return 0;
}