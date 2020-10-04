#include <stdio.h>
#include <stdlib.h>

enum mode
{
    word,
    space,
    quotes
};

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

int main() 
{
	
	LinkedList_t ll = {NULL};
// 	char * s;	
	int i = 0;
	int st = 0;
	int mode = space; //0 - space, 1 - word, 2 - quotes
// 	scanf("%[^\n]s", s);
    /////////////////////////////////////
    i = 0;
    char s[100000];
    char ch;
    i = 0;
    ch = getchar();
    while (ch != '\n') {
        s[i] = ch;
        ch = getchar();
        i++;
    }
    s[i] = '\0';
    i = 0;
    ///////////////////////////////////////////
	while (s[i] != '\0') {		
		switch(mode) {
			case space:
				if (s[i] != ' ') {
					if (s[i] == '\"') {
						mode = quotes;
					} else {
						mode = word;
					}
					st = i;
				}
				break;
			case word:
			    if (s[i] == ' ') {
					mode = space;
					addNode(&ll, substr(s, st, i));
				}
				if (s[i] == '\"') {
					mode = quotes;
					addNode(&ll, substr(s, st, i));
					st = i;
				}
				break;
				
			case quotes:
			    if (s[i] == '\"') {
					mode = space;
					addNode(&ll, substr(s, st+1, i));
				}
				break;
		}		
		i++;
	}
	if (mode == quotes) {
		printf("ERRROR!/n");
		return 1;
	}
	switch(mode) {
		case word:
			addNode(&ll, substr(s, st, i));
			break;
		case quotes:
			addNode(&ll, substr(s, st+1, i));
			break;
	}

  	printAllNode(&ll);
    printf("...................\n");
	return 0;
}
