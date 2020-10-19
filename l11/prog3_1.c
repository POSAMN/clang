#include <stdio.h>

int longString(char * arr)
{
    int i = 0;
    while (arr[i] != '\0') {
        i++;
    }
    return i;
}

int main(int argc, char ** argv)
{
    int i = 0;
    int j = 0;
    if (argc != 3) {
        printf("error\n");
        return 1;
    }
    if (longString(argv[1]) >= longString(argv[2]))
        printf("%s\n", argv[1]);
    else
        printf("%s\n", argv[2]);

}
