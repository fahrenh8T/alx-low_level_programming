#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
  * main - Entry point
  * @argc: number of arguments
  * @argv: array of actual arguments
  *
  * Return: 0 (success)
  */
int main(int argc, char *argv[])
{
	int num1, num2, calc;
	char op;
	int (*resl)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	op = *argv[2];
	resl = get_op_func(argv[2]);

	if (resl == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	if ((op == '/' || op == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	calc = resl(num1, num2);
	printf("%d\n", calc);
	return (0);
}
