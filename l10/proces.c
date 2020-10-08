#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char ** array = malloc(sizeof(char *) * 3);
//     array[0] = "ls";
//     array[1] = "-a";
    for (int i = 0; i < 2; i++) {
        char * s = malloc(sizeof(char) * 4);
        scanf("%s", s);
        int d = strlen(s);
        char * str = malloc(sizeof(char) * (d + 1));
        for (int i = 0; i < strlen(s); i++)
            str[i] = s[i];
        str[d] = '\0';
        printf("%ld\n", strlen(s));
        array[i] = str;
    }
    
    
    int p;
    p = fork();
    if (p == 0) {
        
        execlp(array[0], array[0], array[1], NULL);
        perror("error");
        exit(EXIT_SUCCESS);
    }
    wait(NULL);
    printf("OK\n");
    return 0;
}
