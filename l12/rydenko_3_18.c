#include <stdio.h>

// 3.18. Подсчитать количество натуральных чисел n ( 111 < n < 999 ), в записи которых есть две одинаковые цифры.

int main()
{
    int a = 1000;
    int b = 1010;
    int cur = 0;
    int j = 0;
    int i = a++;
    int g = 1;
    int d = 0;
    for (; i <= b; i++) {
        cur = i % 10;
        a = i;
//         printf("    %d %d\n", a, cur);
        while ( (a != 0) ) {
            a = a / 10;
//             printf("a = %d\n", a);
            while (a != 0) {
//                 printf("    %d\n", a);
                if (cur == a % 10) {
                    j++;
                    //break;
                } 
                a = a / 10;                
           }
            g *= 10;
            a = i / g;
            cur = a % 10;
        }
        printf("%d\n", j);
        if (j == 1) 
            d++;
        j = 0;
        g = 1;
    }
    printf("kolvo word with  2 : = %d", d);
}
