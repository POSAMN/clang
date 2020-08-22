#include <stdlib.h>
#include <stdio.h>
#include "link_list.h"

int main() {
	node_t head = {42, NULL};
	node_t* phead = &head;
	phead = addToHead(phead, 12);
	phead = addToHead(phead, 22);
	phead = addToHead(phead, -1);
	phead = addToHead(phead, 11);
	phead = addToHead(phead, 12);
	phead = addToHead(phead, 13);
	phead = addToHead(phead, 65);
	phead = addToHead(phead, 78);
	phead = addToHead(phead, 90);
	
	printf("%p \n",findByValue(phead, -2));
	
	print(phead);
	
	deleteByValue(phead, -2);
	
	print(phead);
}