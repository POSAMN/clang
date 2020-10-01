#include <stdio.h>
#include <stdlib.h>

/*
 * Cтрока состоит из пробелов маленьких и больших латинских символов посчитать сколько  каждых
 *
 */
enum mode
{
    space,
    symbolbig,
    symbolsmol
};

int main()
{
    FILE* input;
    if ( (input = fopen("text.txt", "r+")) == NULL ) {
        printf("error: can not open file");
        return 2;
    }
    char c;
    int mode = space;
    int space_i = 0;
    int symbolbig_i = 0;
    int symbolsmol_i = 0;
    fscanf(input, "%ch", &c);
    while (!feof(input)){
        switch (mode) {
            case space:
                if (c == ' ') {
                    space_i++;
                }
                else {
                    if ((c <= 'z') & (c >= 'a')) {
                        mode = symbolsmol;
                        symbolsmol_i++;
                    } else {
                        symbolbig_i++;
                        mode = symbolbig;
                    }
                }
                break;
                
            case symbolbig: 
                if ((c <= 'Z') & (c >= 'A')) {
                    symbolbig_i++;
                } else {
                    if ((c <= 'z') & (c >= 'a')) {
                            mode = symbolsmol;
                            symbolsmol_i++;
                    } else {
                        mode = space;
                        space_i++;
                    }
                }
                break;
                
            case symbolsmol:
                if ((c <= 'z') & (c >= 'a')) {
                        symbolsmol_i++;
                } else {
                    if ((c <= 'Z') & (c >= 'A')) {
                        symbolbig_i++;
                        mode = symbolbig;
                    }
                    mode = space;
                    space_i++;
                }
                break;
        }   
      fscanf(input, "%ch", &c);          
    }
    printf("kolvo big = %d; kolvo small = %d; kolvo space = %d;\n", symbolbig_i, symbolsmol_i, space_i);
    fclose(input);
}
