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
    node_t * cur = ll->head;
    printf("!!!!!!!!!!\n");
    while (ll->head->next != NULL) {
        cur = ll->head;
            printf("cur =%s\n", cur->str);
        ll->head = cur->next;
            printf("head->str =%s\n", ll->head->str);
        free(cur);
    }
    free(ll->head);
    ll->head = NULL;
}

//test fo|o bar
int main() 
{
	LinkedList_t ll = {NULL};
	char * s;
	int st = 0;
	int mode = space; //0 - space, 1 - word, 2 - quotes
	int i = 0;
    int d = 1;
    do {
        printf(" please wr:\n");
        s = readFromStdIn();
        mode = space;
        i = 0;
        st = 0;
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
            printf("ERRROR!\n");
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
        free(s);
        printAllNode(&ll);
        clearList(&ll);
//         printAllNode(&ll);
        printf("...................\n");
    } while (d != 0);
	return 0;
}
