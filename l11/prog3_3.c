#include <stdio.h>

int cmp(char * arr1, char * arr2)
{
    int i = 0;
    while (arr1[i] != '\0') {
        if (arr1[i] != arr2[i]) 
            return 0;
        i++;
    }
    if (arr2[i] == '\0') {
        return 1;
    }
    return 0;
}

int main(int argc, char ** argv)
{
    int i;
    int j;
    if (argc == 1) {
        printf("no words\n");
        return 1;
    }
    for (i = 1; i < argc; i++) {
        for (j = i + 1; j < argc; j++) {
            if (argv[j][1] == argv[i][1])
                if (cmp(argv[i], argv[j]) != 0) {
                    printf("yes\n");
                    return 1;
                }
        }
    }
    printf("no\n");
    return 0;
}
