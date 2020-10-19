#include <stdio.h>

int main(int argc, char ** argv)
{
    int i = 0;
    int f = 0;
    if (argc == 3) {
        while ((argv[1][i] != '\0')) {
            if (argv[1][i] == argv[2][i]) {
                i++;
            } else {
                printf("no\n");
                return 1;
            }
        }
        
        if (argv[1][i] == argv[2][i]) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    } else {
        printf("error\n");
        return 1;
    }
}
