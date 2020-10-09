#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    char * arrstr = malloc(sizeof(char) * size);
    int i = 0;
    char c = getchar();
    char * s;
    while (c != '\n') {
        if (i > size - 1) {
            s = malloc(sizeof(char) * size *2);
        }
        s[i] = c;
        i++;
        c = getchar();
    }
    s[i] = '\0';
    printf("%d\n", i);
    printf("%s\n", s);
}
