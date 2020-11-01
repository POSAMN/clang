#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
                   /* ниже наша функция обработки сигнала */
void ctrl_break(int val)
{
        signal (SIGINT, SIG_IGN);
        printf("Для завершен : ");
        getchar();
        exit(0);
}
int main()
{
    if (signal(SIGINT,(&ctrl_break)) == SIG_ERR)
    {
        perror("Не смог установить SIGINT!");
        abort();
    }
    raise(SIGINT);
}
