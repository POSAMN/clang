#include <stdlib.h>
#include <stdio.h>
#include "link_list.h"

void addToTail(node_t* head, int data){
	node_t* cur = head;
	while(cur->next != NULL) {
		cur = cur->next;
	}
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
	new_node->data = data;
	new_node->next = NULL;
	cur->next = new_node;
}

void print(const node_t* head) {
	const node_t* cur = head;
	while(cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
