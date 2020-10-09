#ifndef _NEW_STRING_CUTTER_H_
#define _NEW_STRING_CUTTER_H_

enum mode
{
    word,
    space,
    quotes
};

typedef struct node {
	char * str;
	struct node * next;
} node_t;


typedef struct LinkedList {
	struct node * head;
} LinkedList_t;

char * substr(const char * s, int st, int fn);
char * readFromStdIn();

void addNode(LinkedList_t * ll, char * str);
void printAllNode(const LinkedList_t * ll);
void clearList(LinkedList_t * ll);
int lenList(const LinkedList_t * ll);

char ** createArray(LinkedList_t * ll);
void clearDoubleArray(char ** array, LinkedList_t * ll);
void printDoubleArray(char ** array, LinkedList_t * ll);
void launchProces(char ** array);
#endif
