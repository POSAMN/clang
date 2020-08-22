#include <stdlib.h>
#include <stdio.h>
#include "link_list.h"

void addToTail(node_t* head, int data){
	node_t* cur = head;
	while(cur->next != NULL) {
		printf("! %d\n", data);
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

node_t* addToHead(node_t* oldHead, int data) {
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
	new_node -> data = data;
	new_node -> next = NULL;
	
	if (oldHead != NULL) {
		new_node -> next = oldHead;	
	}

	return new_node;
}



node_t* findByValue(node_t* head, int value) {
	node_t* cur = head;

	while (cur != NULL && cur->data != value)
	{
		cur = cur->next;
	}
	
	return cur;
}


void deleteByValue(node_t* head, int value) {
	node_t* cur = head;
	while (cur->next != NULL && cur->next->data != value)
	{
		cur = cur->next;
	}
	printf("%p\n", cur);
	
	node_t* node_to_remove = cur->next;
	printf("%p\n", node_to_remove);
	fflush(stdout);
	cur -> next = cur ->next->next;
	
	free(node_to_remove);
		
}









