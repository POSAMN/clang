#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char* str;
    struct node* next;
} node_t;

typedef struct LinkedList 
{
	struct node* head;
} LinkedList_t;

 
void addNode(LinkedList_t* ll, char* s, int st, int fn)
{

    node_t* new_node = malloc(sizeof(node_t));
	char* str = malloc(sizeof(char)*(fn - st + 1));
	
	for (int i = st; i < fn; i++) {
		str[i - st] = s[i];
	}
	str[fn-st] = '\0';
	//printf("%s", str);
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


int main() {
	
	LinkedList_t ll = {NULL};
	char * s;
	
	scanf("%[^\n]s", s);
	
	int i = 0;
	int st = 0;
	int isWord = 0;
	while(s[i] != '\0') {
		
		if (!isWord) {
			
			if (s[i] != ' ') {
				isWord = 1;
				st = i;
			} else {
				///
			}
		} else {
			
			if (s[i] != ' ') {
				//
			} else {
				//printf("%c", s[i]);
				addNode(&ll, s, st, i);
				isWord = 0;
			}
		}
		i++;
	}
	if (isWord) {
		addNode(&ll, s, st, i);
	}
	printAllNode(&ll);
	
	return 0;
}