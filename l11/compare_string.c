#include <stdio.h>

// найти количество пар слов у которых начало и конец одинаковые

int compareLastElement(char * s1, char * s2)
{
    int i = 0;
    int j = 0;
    while (s1[i] != '\0') {
        i++;
    }
    while (s2[j] != '\0') {
        j++;
    }
    if (s1[i - 1] == s2[j - 1])
        return 1;
    else return 0;
}

int main(int argc, char ** argv)
{
    int i = 0;
    int j = 0;
    int kolvoword = 0;
    char * s;
    if (argc <= 2) {
        printf("not word ");
        return 1;
    }
    for (i = 1; i < argc; i++) {
        for (j = i + 1; j < argc; j++) {
            argv[i][1] == argv[j][1];
            kolvoword = kolvoword + compareLastElement(argv[i], argv[j]);
        }
    }
    printf("%d\n", kolvoword);
}
