#include <stdio.h>
#include "some_struct.h"

int main() {
	data_t some_data = {100, NULL, 0, 2.1};
	printData(&some_data);
	return 0;
	
}