#include<stdio.h>
#include<stdlib.h>
#include "link_list.h"

void addToTail(LinkedList_t* ll, int value) {
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
	new_node->data = value;
	new_node->next = NULL;
	if (ll->head == NULL) {
		ll->head = new_node;
	} else  {
		node_t* cur = ll->head;
		while(cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = new_node;
	}
}

void addToHead(LinkedList_t* ll, int value){
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
	new_node -> data = value;
	new_node -> next = NULL;
	
	if (ll->head != NULL) {
		new_node -> next = ll->head;	
	}

	ll->head = new_node;
}

void deleteByValue_(LinkedList_t* ll, int value){
	if (ll->head == NULL) {
		return;
	}
	node_t* cur = ll->head;
	while(cur->next != NULL && cur->next->data != value) {
		cur = cur->next;
	}
	if (cur->next == NULL) {
		return;
	}
	node_t* node_for_delete = cur->next;
	cur->next = cur->next->next;
	
	free(node_for_delete);
	
}

void deleteByValue(LinkedList_t* ll, int value){
	node_t* prev = NULL;
	node_t* cur = ll->head;
	while(cur != NULL && cur->data != value) {
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL) {//ничего не нашли или список был пуст
		return;
	}
	if (prev == NULL) {//удаляемое значение в голове списка!
		node_t* node_for_delete = cur;
		ll->head = cur->next;
		free(node_for_delete);
	} else {
		prev->next = cur->next;
		free(cur);
	}
		
}


void print(const LinkedList_t* ll) {
	const node_t* cur = ll->head;
	while(cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
