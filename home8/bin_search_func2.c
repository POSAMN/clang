#include <stdio.h>
#include <stdlib.h>

int cmpOnTryArray(double* arr, int start, int size, double valueleft, double valueright)
{
    
    if (arr[1] > valueright){
        return 1;
    } else if (arr[size] < valueleft){
            return 1;
    } else if ((arr[1] >= valueleft) & (arr[1] <= valueright)) {
            printArrayLeft(arr, start, size, valueright);
        } else if ( (arr[size] >= valueleft) & (arr[size] <= valueright) ) {
                printArrayRight(arr, start, size, valueleft);
        }
        int j = size % 2;
        int fin = size/2;
        
        cmpOnTryArray(arr, start, fin + j, valueleft, valueright);
        cmpOnTryArray(arr, fin + j * 2, size, valueleft, valueright);
    }
    return 1;
}

void printArrayLeft(double* arr, int start, int size, double valueright)
{
    int i = 0;
    while ( (arr[i] <= valueright) & (i <= size) ){
        printf("%lf", arr[i]);
        i++;
    }
}

void printArrayRight(double* arr, int start, int size, double valueleft)
{
    int i = size;
    while ( (arr[i] >= valueleft) & (i <= 0) ){
        printf("%lf", arr[i]);
        i--;
    }
}



