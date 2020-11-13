#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


static volatile int alive = 0;

void handler()
{
    alarm(1);
    alive++;
}

void myAlarm()
{
    if (alive == 3){
        exit(0);
    }
    alive = 0;
}

int main()
{
    signal(SIGINT, handler);
    signal(SIGALRM, myAlarm);
    int c;
    while ((c = getchar()))
        if (c == '\n') {
            printf("OK\n");
        }
}
