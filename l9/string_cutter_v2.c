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


char* substr(const char* s, int st, int fn)
{
	char* str = malloc(sizeof(char)*(fn - st + 1));
	
	for (int i = st; i < fn; i++) {
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


int main() 
{
	
	LinkedList_t ll = {NULL};
	char * s;
	
	scanf("%[^\n]s", s);
	
	int i = 0;
	int st = 0;
	int mode = 0; //0 - пробелы, 1 - слова, 2 - фразы
	while (s[i] != '\0') {
		
		switch(mode) {
			case 0:
				if (s[i] != ' ') {
					if (s[i] == '\"') {
						mode = 2;
					} else {
						mode = 1;
					}
					st = i;
				}
				break;
			case 1:
			    if (s[i] == ' ') {
					mode = 0;
					addNode(&ll, substr(s, st, i));
				}
				if (s[i] == '\"') {
					mode = 2;
					addNode(&ll, substr(s, st, i));
					st = i;
				}
				break;
				
			case 2:
			    if (s[i] == '\"'){
					mode = 0;
					addNode(&ll, substr(s, st+1, i));
				}
				break;
		}		
		i++;
	}
//	if (mode == 2) {
//		printf("ERRROR!/n");
//		return 1;
//	}
	switch(mode) {
		case 1:
			addNode(&ll, substr(s, st, i));
			break;
		case 2:
			addNode(&ll, substr(s, st+1, i));
			break;
	}
	
	printAllNode(&ll);
	return 0;
}
