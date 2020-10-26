#include <stdio.h>

int main()
{
    int i;
    int sum;
    i = 6; 
    sum = 0;
    for ( ; i <= 10; i++) sum += i;
    printf("%d %d\n", i, sum); 
    i = 0;
    for (; i <= 10; i++);
    printf("%d\n", i);
    
    sum = 0;
    for ( i = 1; i <= 1;) sum += ++i;
    printf("%d %d\n", i, sum);
    
    for ( i = 1, sum = 0; i <= 10; sum += i,  i++);
    printf("%d %d\n", i, sum);
    
    for ( i = 1, sum = 0; i <= 10; sum += i++);
    printf("%d %d\n", i, sum);
    
    for ( i = 0, sum = 0; i++, i <= 10; sum += i);
    printf("%d %d\n", i, sum);
    
    for ( i = 0, sum = 0; i++, i <= 10;  sum += i);
    printf("%d %d\n", i, sum);
}
