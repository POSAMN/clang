#include<stdio.h>
#include<stdlib.h>

void pr(int rows, int size, int** arrd);
int** allocate2dArray(int rows, int size)
{
    int** arrd = (int**)malloc(rows*sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        int a = i + 2;
        int b = 1;
        arrd[i] = (int*)malloc(size * sizeof(int));
        arrd[i][0] = 1;
        for (int j = 1; j < size; j++)
        {   
            b = b * a;
            arrd[i][j] = b;
        }
    }  
    pr(rows, size, arrd);
    return arrd;
}

void pr(int rows, int size, int** arrd)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arrd[i][j]);
        }
        printf("\n");
    }
}
 void free2dArray(int** p, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(p[i]);
    }
    free(p);
}
int main(){
    int rows = 5;
    int size = 3;
    int** s = allocate2dArray(rows, size);
    printf("eeee\n");
    printf("%p\n", s);
    pr(rows, size, s);
    free2dArray(s, rows);
}



