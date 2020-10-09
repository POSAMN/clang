#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "new_string_cutter.h"

char* substr(const char* s, int st, int fn)
{
	char* str = malloc(sizeof(*str) * (fn - st + 1));
	int i;
	for (i = st; i < fn; i++) {
		str[i - st] = s[i];
	}
	str[fn-st] = '\0';
	return str;
}
 
void addNode(LinkedList_t* ll, char* str)
{
    node_t* new_node = malloc(sizeof(node_t));
    new_node->str = str;
    new_node->next = NULL;
    if (ll->head == NULL){
        ll->head = new_node;
    } else {
        node_t* cur = ll->head;
        while (cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new_node;
    }    
}

void printAllNode(const LinkedList_t* ll)
{
    const node_t* cur = ll->head;
    while (cur != NULL){
       printf("%s\n", cur->str);
       cur = cur->next;
    }
}

char * readFromStdIn() {
	int size = 10;
	int i = 0;
	char * s = malloc(sizeof(*s) * size);
	char c = getchar();
	while (c != '\n' && c != '\0') {
		
		if (i > size -1) {
			char * newS = malloc(sizeof(*newS) * size * 2);
			for (int j = 0; j < size; j++){
				newS[j] = s[j];
			}
			size *= 2;
			free(s);
			s = newS;
		}
		
		s[i++] = c;
		c = getchar();
	}
	
	s[i] = '\0';
	return s;
} 


void clearList(LinkedList_t* ll) 
{
   node_t* cur = ll->head;
   node_t* prev = NULL;
   while(cur != NULL) {
       prev = cur;
       cur = cur->next;
       free(prev->str);
       free(prev);
  }
  ll->head = NULL;
}
///////////////////////////////// 2222222222222222222222222222222222222222222222222222222222222222222222222
int lenList(const LinkedList_t * ll)
{
    node_t * cur = ll->head;
    int i = 0;
    while (cur != NULL) {
        cur = cur->next;
        i++;
    }
    return i;
}
char ** createArray(LinkedList_t * ll)
{
    node_t * cur = ll->head;
    int d = lenList(ll);
    char ** array = malloc(sizeof(char*) * (d + 1));
    for (int i = 0; i < d; i++) {
        array[i] = cur->str;
        cur = cur->next;
    }
    array[d] = NULL;
    return array;
}

// void clearDoubleArray(char ** array, LinkedList_t * ll)
// {
//     int size = lenList(ll);
//     for (int i = 0; i < size; i++) {
//         free(array[i]);
//     }
//     free(array);
// }


void printDoubleArray(char ** array, LinkedList_t * ll)
{
    int size = lenList(ll);
    for (int i = 0; i <= size; i++) {
        printf("%s ", array[i]);
    }
}

int isEquals(char * s1, char * s2) {
	int i = 0;
	while(s1[i] != '\0' && s2[i] != '\0') {
		if (s1[i] != s2[i]) {
			return 0;
		}
		i++;
	}
	
	return s1[i] == '\0' && s2[i] == '\0';
}

void launchProces(char ** array)
{
    int p;
    p = fork();
    if (p == 0) {
        if (isEquals(array[0], "cd")) {
            chdir(array[1]);
        } else {
            execvp(array[0], array);
        }
        perror("Result");
        exit(0);
    }
    wait(NULL);
    printf("OK\n");
}











