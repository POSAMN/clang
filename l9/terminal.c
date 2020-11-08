#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

//разрезать строчку на слова и если есть "" то их не учитывать если их нечетное то ошибку выводитьа делать так:
// ввод:  rfgfg"dgdfb  d"gdgd
// вывод: rfgfgdgdfb    dgdgd

#ifdef DEBUG
#define debug(fmt) printf("DEBUG:\t\t%s:%s:%d: "fmt"\n", __FILE__, __FUNCTION__, __LINE__)
#define debug2(fmt, arg) printf("DEBUG:\t\t%s:%s:%d: "fmt"\n", __FILE__, __FUNCTION__, __LINE__, arg)
#else
#define debug(fmt)
#define debug2(fmt, arg)
#endif

enum mode {
    word,
    space,
    quotes
};

typedef struct node {
    char *str;
    struct node *next;
} node_t;


typedef struct LinkedList {
    struct node *head;
} LinkedList_t;


char *substr(const char *s, int st, int fn) {
    debug("malloc");
    char *str = malloc(sizeof(*str) * (fn - st + 1));
    debug2("malloc result=%p", str);
    int i;
    for (i = st; i < fn; i++) {
        str[i - st] = s[i];
    }
    str[fn - st] = '\0';
    return str;
}

void addNode(LinkedList_t *ll, char *str) {
	if (strlen(str) == 0) {
		return;
	}
    debug("malloc");
    node_t *new_node = malloc(sizeof(node_t));
    debug2("malloc result=%p", str);
    new_node->str = str;
    new_node->next = NULL;
    if (ll->head == NULL) {
        ll->head = new_node;
    } else {
        node_t *cur = ll->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
}

void printAllNode(const LinkedList_t *ll) {
    const node_t *cur = ll->head;
    while (cur != NULL) {
        printf("%s\n", cur->str);
        cur = cur->next;
    }
}

char *readFromStdIn() {
    int size = 10;
    int i = 0;
    int c = getchar();
    debug("malloc");
    char *s = malloc(sizeof(*s) * size);
    debug2("malloc result=%p", str);
    int j;
    while (c != '\n' && c != '\0') {

        if (i > size - 1) {
            debug("malloc");
            char *newS = malloc(sizeof(*newS) * size * 2);
            debug2("malloc result=%p", str);
            for (j = 0; j < size; j++) {
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


void clearList(LinkedList_t *ll) {
    node_t *cur = ll->head;
    node_t *prev = NULL;
    while (cur != NULL) {
        prev = cur;
        cur = cur->next;
        free(prev->str);
        free(prev);
    }
    ll->head = NULL;
}

///////////////////////////////// 2222222222222222222222222222222222222222222222222222222222222222222222222
int lenList(const LinkedList_t *ll) {
    node_t *cur = ll->head;
    int i = 0;
    while (cur != NULL) {
        cur = cur->next;
        i++;
    }
    return i;
}

char **createArray(LinkedList_t *ll) {
    int d = lenList(ll);
    if (d == 0) {
        return NULL;
    }
    node_t *cur = ll->head;
    debug("malloc");
    char **array = malloc(sizeof(char *) * (d + 1));
    debug2("malloc result=%p", str);
    int i;
    for (i = 0; i < d; i++) {
        array[i] = cur->str;
        cur = cur->next;
    }
    array[d] = NULL;
    return array;
}

void printDoubleArray(char **array, LinkedList_t *ll) {
    int size = lenList(ll);
    int i;
    for (i = 0; i <= size; i++) {
        printf("%s ", array[i]);
    }
}

int isEquals(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0;
        }
        i++;
    }

    return s1[i] == '\0' && s2[i] == '\0';
}

/*
проверяет кол-во амперсантов в строке
если амперсант присуствует и он единственный и явлется частью команды, а так же после него ничего кроме пробелов или \n нет, то ф-я возвращает 1
если амперсант - это последняя команда, то возвращаем 2
если амперсанты отсутствуют то 0
иначе -1 
*/
int proceedAmpersants(char** argv, int argc) {
	int i = 0;
	int amp = 0;
	for (; i < argc; i++) {
		int j = 0;
		for (;argv[i][j] != '\0'; j++) {
			if (argv[i][j] == '&') {
				amp++;
				if (i < argc -1) {
					//амперсант не в последней команде
					return -1;
				}
			}
		}
	}
	
	if (amp == 1) {
		char * comWithAmp = argv[argc-1];
		int len = 0;
		while(comWithAmp[len++] != '\0') {}
		/*
			последняя команда состоит только из амперсанта
		*/
		if (len == 2) {
			argv[argc-1] = NULL;
			return 2;
		} else {
			//последний символ - амперсант
			if (comWithAmp[len - 2] == '&') {
				comWithAmp[len - 2] = '\0';
				return 1;
			} else {
				return -1;
			}
		}
		
	} else if (amp > 1) {
		return -1;
	}
	return 0;
}

void launchProcess(char **array, int argc) {
    if (array == NULL) {
        return;
    }
    int p;
	int ampersants = proceedAmpersants(array, argc);
	
	if (ampersants != -1) {//ошибки с амперсантом нет
	if (ampersants == 2) {
		if (--argc == 0) {
			errno = EINVAL;
			perror("Нет команды для исполнения");
			return;
		}
	}
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
		//printf("amp = %d\n", ampersants);
		if (ampersants == 0) {
			wait(NULL);
		}
	} else {
		errno = EINVAL;
		perror("Неверно использованы амперсанты");
	}
}


char *concat(char *s1, char *s2) {
    int size1 = 0;
    int size2 = 0;

    for (; s1[size1] != '\0'; size1++) {}
    for (; s2[size2] != '\0'; size2++) {}
    int newSize = (size1 + size2 - 1);
    debug("malloc");
    char *newString = malloc(sizeof(char) * newSize);
    debug2("malloc result=%p", str);

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

char *clearQuotes(char *s) {
    int i = 0;
    int quotes = 0;
    while (s[i] != '\0') {
        if (s[i] == '\"') quotes++;
        i++;
    }

    if (quotes % 2 == 1) {
        free(s);
        return NULL;
    }
    debug("malloc");
    char *ss = malloc(i - quotes + 1);
    debug2("malloc result=%p", str);
    int j = 0;
    int k = 0;
    while (s[j] != '\0') {
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

int main() {
    LinkedList_t ll = {NULL};
    char *s;
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
                    char *word = substr(s, st, i);
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
        char **array = createArray(&ll);
        launchProcess(array, argc);
        free(array);

        clearList(&ll);
        printf("...................\n");
    } while (d != 0);
    return 0;
}
