#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <signal.h>

static volatile int alive = 1;

void handler()
{
    alive = 0;
}

int main()
{
    int pipe1[2];
    int pipe2[2];
    int pid;
    int buf = 1;
    int read_pipe, write_pipe;
    char * name;
    signal(SIGINT, handler);
    if (pipe(pipe1) || pipe(pipe2)) {
        printf("erro create pipe\n");
        return 3;
    }
    pid = fork();
    if (pid){
        name = "parent";
        read_pipe = pipe1[0];
        write_pipe = pipe2[1];
        write(pipe2[1], &buf, sizeof(buf));
    } else {
        name = "child";
        read_pipe = pipe2[0];
        write_pipe = pipe1[1];
    }
    while(alive) {
        read(read_pipe, &buf, sizeof(buf));
        printf("[%s], got %d\n", name, buf);
        buf++;
        sleep(2);
        write(write_pipe, &buf, sizeof(buf));
    }
    
    return 0;
}
