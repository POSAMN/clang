#include <stdio.h>

// 2.20. Определить число, полученное выписыванием в обратном порядке цифр заданного целого трехзначного числа.

int main()
{
	int d;
	int value;
	int result = 0;
    scanf("%d", &value);
	d = value % 10;
	while ((d != 0) & (value != 0)) {
		result = result * 10 + d;
		value = (int)value / 10;
		d = value % 10;
	}
	printf("it is turn element = %d\n", result);
}
