#include <stdlib.h>

#ifndef _DYNAM_ARRAY_H_
#define _DYNAM_ARRAY_H_

typedef struct dyn_arr {
	int * buf;
	size_t buf_size;//размер области памяти на которую указывает arr_ptr
	size_t size;//фактический размер полезных данных в буфере
} dyn_arr_t;

dyn_arr_t createDynArray();
void add(dyn_arr_t* arr, int value);
void print(const dyn_arr_t* arr);
void clearDynArray(dyn_arr_t* arr);


#endif