#include<stdio.h>
#include<stdlib.h>
#include "link_list.h"

int main() {
	LinkedList_t ll = {NULL};
	addToTail(&ll, 12);
	addToTail(&ll, 1);
	addToTail(&ll, 56);
	addToTail(&ll, 144);
	addToTail(&ll, 3);
	addToTail(&ll, 2);
	addToTail(&ll, 5);
	addToTail(&ll, 8);
	addToHead(&ll, 89);
	print(&ll);
	
	deleteByValue(&ll, -1);
	
	
	print(&ll);
	
	
	return 0;
}
