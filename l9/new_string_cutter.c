#include <stdio.h>
#include <stdlib.h>
#include "new_string_cutter.h"

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
                        addNode(&ll, substr(s, st + 1, i));
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
                addNode(&ll, substr(s, st , i));
                break;
            case quotes:
                addNode(&ll, substr(s, st + 1, i));
                break;
        }
        free(s);
        printAllNode(&ll);
//          printAllNode(&ll);
        printf("print size List = %d\n", lenList(&ll));
        createArray(&ll);
        clearList(&ll);
        printf("...................\n");
    } while (d != 0);
	return 0;
}
