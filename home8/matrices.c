
#include <stdio.h>
#include <stdlib.h>
//определить структуру матрица 3x3
//определить операции сложения матриц и умножения матриц



typedef struct matrica
{
    double** mas;
    int len;
    int hight;
} matrica_t;

matrica_t creatMatrica(matrica_t mtr)
{
    mtr.hight = 3;
    mtr.len = 3;
    mtr.mas = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < mtr.hight; i++){
        mtr.mas[i] = (double*)malloc(3 * sizeof(double));
        for (int j = 0; j < mtr.len; j++){
            scanf("%lf", &mtr.mas[i][j]);
        }
    }
    return mtr; 
}

void printMatrica(matrica_t mtr)
{
    for (int i = 0; i < mtr.hight; i++){
        for (int j = 0; j < mtr.len; j++)
            printf("%.1lf ", mtr.mas[i][j]);
        printf("\n");
    }
    printf("////////////\n");
}

matrica_t sumMtr1Mtr2(matrica_t mtr1, matrica_t mtr2)
{
    for (int i = 0; i < mtr1.hight; i++)
        for (int j = 0; j < mtr1.len; j++)
            mtr1.mas[i][j] += mtr2.mas[i][j];
    return mtr1;
}
int main()
{
    printf("LETs go \n");
    matrica_t mtr1 = creatMatrica(mtr1);
    matrica_t mtr2 = creatMatrica(mtr2);
    printMatrica(mtr1);
    printMatrica(mtr2);
    mtr1 = sumMtr1Mtr2(mtr1, mtr2);
    printMatrica(mtr1);
    
}


