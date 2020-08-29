#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

typedef struct node {
	int data;
	struct node* next;
} node_t;


typedef struct LinkedList {
	struct node* head;
} LinkedList_t;

void addToTail(LinkedList_t* ll, int value);
void addToHead(LinkedList_t* ll, int value);
void deleteByValue(LinkedList_t* ll, int value);
void print(const LinkedList_t* ll);

//homework!
void deleteFromTail(LinkedList_t* ll);
void deleteFromHead(LinkedList_t* ll);
int findByValue(LinkedList_t* ll, int value);//0 -not found, 1 - found
int size(LinkedList_t* ll);
#endif