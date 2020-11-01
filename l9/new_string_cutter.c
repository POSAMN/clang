#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        int c = getchar();
        int j;
        while (c != '\n' && c != '\0' && c != EOF) {
			
                if (i > size -1) {
                        char * newS = malloc(sizeof(*newS) * size * 2);
                        for (j = 0; j < size; j++){
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
	if (d == 0) {
		return NULL;
	}
	
    char ** array = malloc(sizeof(char*) * (d + 1));
    int i;
    for (i = 0; i < d; i++) {
        array[i] = cur->str;
        cur = cur->next;
    }
    array[d] = NULL;
    return array;
}

void printDoubleArray(char ** array, LinkedList_t * ll)
{
    int size = lenList(ll);
    int i;
    for (i = 0; i <= size; i++) {
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

void launchProcess(char ** array, int argc)
{
	if (array == NULL) {
		printf("Please, insert valid command");
		return;
	}
    int p;
        if (isEquals(array[0], "cd")) {
                if (argc <= 2) {
                        int chdirResult = chdir(array[1]);
                        printf("chdirResult = %d\n", chdirResult);
                        perror("cd result");
                } else {
                        printf("cd must have 1 argument");
                        return;
                }
        } else {
    p = fork();
                if (p == 0) {
                        execvp(array[0], array);
                        perror("Result");
                        exit(0);
                }
        }
    wait(NULL);
}


char* concat(char* s1, char* s2) {
        int size1 = 0;
        int size2 = 0;

        for(; s1[size1] != '\0'; size1++) {}
        for(; s2[size2] != '\0'; size2++) {}
        int newSize = (size1 + size2 - 1);
        char* newString = malloc(sizeof(char) * newSize);

        int k1 = 0;
        int k2 = 0;
        int i;
        for (i = 0; i < newSize - 1; i++) {
                if (k1 < size1) {
                        newString[i] = s1[k1++];
                } else if (k2 < size2) {
                        newString[i] = s2[k2++];
                }
        }

        newString[newSize - 1] = '\0';

        return newString;

}

char* clearQuotes(char* s) {
        int i = 0;
        int quotes = 0;
        while(s[i] != '\0') {
                if (s[i] == '\"') quotes++;
                i++;
        }

        if (quotes % 2 == 1) {
                return NULL;
        }
        char* ss = malloc(i - quotes);

        int j = 0;
        int k = 0;
        while(s[j] != '\0') {
                if (s[j] == '\"') {
                        j++;
                } else {
                        ss[k] = s[j];
                        k++;
                        j++;
                }
        }
        ss[k] = '\0';
        free(s);
        return ss;
}

int main()
{
        LinkedList_t ll = {NULL};
        char * s;
        int st = 0;
        int mode = space;
        int i = 0;
    int d = 1;
    do {
        printf(" please wr:\n");
        s = readFromStdIn();
	
        mode = space;
        i = 0;
        st = 0;
        int err = 0;
		
        while (1) {
            if (s[i] == ' ' || s[i] == '\0') {
                                if (mode == word) {
                                        mode = space;
                                        char * word = substr(s, st, i);
                                        word = clearQuotes(word);
                                        if (word == NULL) {
                                                printf("%s", "ERROR! WRONG QUOTES\n");
                                                err = 1;
                                                break;
                                        }
                                        addNode(&ll, word);
                                }
                                if (s[i] == '\0') {
                                        if (mode == quotes) {
                                                printf("%s", "ERROR! WRONG QUOTES\n");
                                                err = 1;
                                        }
                                        break;
                                }
                        } else if (s[i] == '\"') {
                                if (mode != quotes) {
                                        /*close qotes*/
                                        if (mode == space) {
                                                st = i;
                                        }
                                        mode = quotes;
                                } else {
                                        /*open quotes*/
                                        mode = word;
                                }

                        } else {
                                if (mode == space) {
                                        mode = word;
                                        st = i;
                                }
                        }
            i++;
        }
                free(s);
                if (err) {
                        continue;
                }
				
                printAllNode(&ll);
                int argc = lenList(&ll);
                char ** array = createArray(&ll);
                launchProcess(array, argc);
                free(array);

        clearList(&ll);
        printf("...................\n");
    } while (d != 0);
        return 0;
}