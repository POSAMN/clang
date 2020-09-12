#include <stdio.h>
#include <stdlib.h>

void cutArray(double* arr, int size, double* arrleft, double* arrright, int j);
void cmpOnTryArray(double* arr, int size, double valueleft, double valueright);
void printArrayLeft(double* arr, int size, double valueright);
void printArrayRight(double* arr, int size, double valueleft);



void cutArray(double* arr, int size, double* arrleft, double* arrright, int j)
{
    
    arrleft =  (double*)malloc((size + j) * sizeof(double));
    arrright = (double*)malloc((size - j) * sizeof(double));
    arrleft = arr * (size - 1) * 4;
}

int cmpOnTryArray(double* arr, int size, double valueleft, double valueright, double* arrleft, double* arrleft)
{
    
    if (arr[1] > valueright){
        return 1;
    } else {
        if ((arr[size] < valueleft){
            return 1;
        }
    } else {
        if ( (arr[1] >= valueleft) & (arr[1] <= valueright) ) {
            printArrayLeft(arr, size, valueright);
        } else {
            if ( (arr[size] >= valueleft) & (arr[size] <= valueright) ) {
                printArrayRight(arr, size, valueleft);
            }  
        }
        int j = size % 2;
        size = size/2;
        
        cutArray(arr, size, arrleft, arrright, j);
        cmpOnTryArray(arrleft, size + j, valueleft, valueright);
        cmpOnTryArray(arrright, size - j, valueleft, valueright);
        
    }
    return 1;
}

void printArrayLeft(double* arr, int size, double valueright)
{
    int i = 0;
    while ( (arr[i] <= valueright) & (i <= size) ){
        printf("%lf", arr[i]);
        i++;
    }
}

void printArrayRight(double* arr, int size, double valueleft)
{
    int i = size;
    while ( (arr[i] >= valueleft) & (i <= 0) ){
        printf("%lf", arr[i]);
        i--;
    }
}



