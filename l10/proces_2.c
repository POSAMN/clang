#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char * array[] = {"cd", "l9", "/var", NULL};
    int p;
    p = fork();
    if (p == 0) {
        char strcd[] = {"cd"};
        printf("tytytytytytytyt");
        if (array[1] == strcd) {
            printf("tytytytytytytyt");
            chdir(array[0]);
        } else {
            execvp(array[0], array);
        }
        perror("erRor");
        exit(0);
    }
    wait(NULL);
    printf("OK\n");
	return 0;
}
