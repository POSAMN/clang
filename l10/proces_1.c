#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int p;
    p = fork();
    p = fork();
    if (p == 0) {
        execlp("ls", "ls", "-a", "-l", NULL);
        perror("ls");
        exit(EXIT_SUCCESS);
    }
    wait(NULL);
    printf("OK\n");
    return 0;
}
