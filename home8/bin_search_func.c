#include <stdio.h>


void cutArray(double* arr, int size, double* arrleft, double* arrright);
void cmpOnTryArray(double* arr, int size, double valueleft, double valueright);
void printArrayLeft(double* arr, int size, double valueright);
void printArrayRight(double* arr, int size, double valueleft);



void cutArray(double* arr, int size, double* arrleft, double* arrright)
{
    size = size/2;
    double* arrleft =  arr;
    double* arrright = arr*(size*4);
}

void cmpOnTryArray(double* arr, int size, double valueleft, double valueright, double* arrleft, double* arrleft)
{
    
    if (arr[1] > valueright){
        return;
    } else {
        if ((arr[size] < valueleft){
            return;
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
        
        cutArray(arr, size, arrleft, arrright);
        cmpOnTryArray(arrleft, size + j, valueleft, valueright);
        cmpOnTryArray(arrright, size, valueleft, valueright);
        
    }
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



