#include <stdio.h>
#include "dynam_array.h"
const size_t INIT_SIZE = 10;

dyn_arr_t createDynArray() {
	dyn_arr_t arr;
	arr.buf = (int*)malloc(INIT_SIZE * sizeof(int));
	arr.buf_size = INIT_SIZE;
	arr.size = 0;
	return arr;
}

void add(dyn_arr_t* arr, int value) {
	if (arr->size == arr->buf_size) {
		size_t new_buf_size = arr->buf_size * 2;
		int* new_buf = (int*)malloc(new_buf_size * sizeof(int));
		for (size_t i = 0; i < arr->size; i++){
			new_buf[i] = arr->buf[i];
		}
		free(arr->buf);
		arr->buf = new_buf;
		arr->buf_size = new_buf_size; 
	}
	arr->buf[arr->size++] = value;
}

void print(const dyn_arr_t* arr) {
	for (size_t i = 0; i < arr->size; i++) {
		printf("%d ", arr->buf[i]);
	}	
	printf("\n");
}

void clearDynArray(dyn_arr_t* arr) {
	free(arr->buf);
	arr->size = 0;
	arr->buf_size = 0;
}

int* get(const dyn_arr_t* arr, size_t ind) {
	if (ind < arr->size) {
		return &(arr->buf[ind]);
	}
	return NULL;
}

void deleteElement(dyn_arr_t* arr, size_t ind) {
	for(size_t i = ind; i < arr->size-1; ++i){
		arr->buf[i] = arr->buf[i+1];
	}
	arr->size--;
}


