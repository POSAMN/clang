#include <stdio.h>

int main()
{
    int i = 0;
    char c = getchar();
    char * s;
    while (c != '\n') {
        i++;
        c = getchar();
    }
    printf("%d\n", i);
}
