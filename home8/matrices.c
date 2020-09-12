#include <stdio.h>
#include <stdlib.h>
//определить структуру матрица 3x3
//определить операции сложения матриц и умножения матриц



typedef struct matrica
{
    double** mas;
    int length;
    int height;
} matrica_t;

matrica_t* createEmptyMatrix(int length, int height) {
	matrica_t* mat = (matrica_t*) malloc(sizeof(matrica_t));
	mat -> length = length;
	mat -> height = height;
	mat -> mas = (double**) malloc(mat->height * (sizeof(double*)));
	
	for (int i = 0; i < mat -> height; i++){
		mat -> mas[i] = (double*) malloc(mat -> length * sizeof(double));
	}
	
	return mat;
}

matrica_t* createMatrixFromConsole()
{
	int length, height;
	printf("input size length: ");
	scanf("%d", &length);
	printf("\n");
	printf("input size height: ");
	scanf("%d", &height);
	printf("\n");
	
	matrica_t* mat = createEmptyMatrix(length, height);
	
    for (int i = 0; i < mat -> height; i++){
		printf("input %d values for row %d: ", mat-> length, i);
        for (int j = 0; j < mat -> length; j++){
            scanf("%lf", &mat -> mas[i][j]);
        }
    }
	printf("\n**************\n\n");
    return mat; 
}

void printMatrica(const matrica_t* mtr)
{
    for (int i = 0; i < mtr->height; i++){
        for (int j = 0; j < mtr->length; j++)
            printf("%.04lf ", mtr->mas[i][j]);
        printf("\n");
    }
    printf("////////////\n\n");
}


/**
	возвращает новую матрицу, которая является суммой матриц @m1 и @m2
	возвращает NULL если матрицы не совместимы по размеру
*/
matrica_t* sumMatrix(const matrica_t* m1, const matrica_t* m2)
{
	if (m1->height != m2->height || m1->length != m2->length) {
		return NULL;
	}
	matrica_t* sumM = createEmptyMatrix(m1->length, m1->height);
	
    for (int i = 0; i < m1 -> height; i++){
        for (int j = 0; j < m1->length; j++) {
			sumM->mas[i][j] = m1->mas[i][j] + m2->mas[i][j];
		}
	}
    return sumM;
}


int main()
{
	/*
    printf("LETs go \n");
    matrica_t mtr1 = creatMatrica(mtr1);
    matrica_t mtr2 = creatMatrica(mtr2);
    printMatrica(mtr1);
    printMatrica(mtr2);
    mtr1 = sumMtr1Mtr2(mtr1, mtr2);
    printMatrica(mtr1);
	*/
	
	matrica_t* m1 = createMatrixFromConsole();
	matrica_t* m2 = createMatrixFromConsole();
	matrica_t* m3 = sumMatrix(m1, m2);
	printMatrica(m1);
	printMatrica(m2);
	printMatrica(m3);
    return 0;
}

//3 3 100 10 1 -1 2 6.0 11 11 .1

//3 3 11 15 0 6 12 18 4 5 123