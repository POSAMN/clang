#include<stdio.h>
#include<stdlib.h>

typedef struct komp
{
    double dei;
    double mni;
}komp;

komp* comadd(komp k1, komp k2)
{
    komp* mas = (komp*)malloc(2*sizeof(komp));
    komp k3;
    k3.dei = k1.dei + k2.dei;
    k3.mni = k1.mni + k2.mni;
    mas [0] = k3;
    k3.dei = 0;
    k3.mni = 0;
    k3.dei = k1.dei - k2.dei;
    k3.mni = k1.mni - k2.mni;
    mas[1];
    return mas;
}

int main()
{
    double a = 2;
    double b = 5;
    double c = 2;
    double d = 5;
    komp k1;
    komp k2;
    k1.dei = a;
    k1.mni = b;
    k2.dei = a;
    k2.mni = b;
    komp* result =  comadd(k1,k2);
    for (int i = 0; i < 2; i++)
    {
        printf("add = %1f + i%1f\n", result[i].dei, result[i].mni);
    }
    return 0;
}
