#include <stdio.h>
#include "dynam_array.h"

int main() {
	dyn_arr_t test_array = createDynArray();
	add(&test_array, 100);
	add(&test_array, 42);
	add(&test_array, 12);
	add(&test_array, -141);
	add(&test_array, 100);
	add(&test_array, 42);
	add(&test_array, 12);
	add(&test_array, -141);
	add(&test_array, 100);
	add(&test_array, 42);
	add(&test_array, 12);
	add(&test_array, -141);
	add(&test_array, 42);
	add(&test_array, 12);
	add(&test_array, -141);
	add(&test_array, 100);
	add(&test_array, 42);
	add(&test_array, 12);
	add(&test_array, -141);
	printf("array size = %ld\n", test_array.size);
	print(&test_array);
	clearDynArray(&test_array);
	return 0;
}