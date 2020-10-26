#include <stdio.h>

// 3.21 Подсчитать количество цифр в десятичной записи целого неотрицательного числа n.

int main()
{
    int n;
    int i = 0;
    printf("n = ");
    scanf("%d", &n);
//     n = 123;
    printf("%d\n", n);
    if (n == 0)
        i = 1;
    else
        while(n != 0) {
            n = n / 10;
            printf("%d\n", n);
            i++;
        }
    printf("kolvo chisel in n : = %d\n", i);
}
