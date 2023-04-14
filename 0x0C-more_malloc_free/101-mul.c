#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int multiply(int num1, int num2)
{
	return (num1 * num2);
}

int main(int argc, char *argv[])
{
	int num1, num2, ans;
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	ans = multiply(num1, num2);

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}
	else
		printf("%d\n", ans);

	return (0);
}
