#include <stdio.h>
#include <stdlib.h>
#include "some_struct.h"


const char * template = "num = %d; volume = %f; ints[0] = %d\n";

void printData(const data_t* d)  {
	printf(template, d->num, d->volume, d->ints[0]);
	
}