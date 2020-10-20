#include <stdio.h>

int main()
{
    int i = 0;
    int d = 0;
    int sem = 0;
    int r = 1;
    char c;
    c = getchar();
    do {
        while (c != '\n') {
            if (c != ' ') {
                i++;
            } else {
                if (i != 0) {
                    if (i <= 2)
                        d++;
                    if (i >= 7)
                        sem++;
                }
                i = 0;
            }
            c = getchar();
        }
        if (i != 0) {
            if (i <= 2)
                d++;
            if (i >= 7)
                sem++;
        }
        printf("%d %d\n", sem, d);
        c = getchar();
        i = 0;
        d = 0;
        sem = 0;
    } while (r != 0);
}
