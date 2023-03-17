#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 * This program assigns a random number to the variable.
 * Excutes and prints the last digit of n and whether >5, <6 and not 0 or 0
 * Return: Always 0 (success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	last_digit = abs(n) % 10;

	printf("Last digit of %d is %d", n, last_digit);

	if (last_digit > 5)
	{
		printf("and is greater than 5\n");
	}
	else if (last_digit == 0)
	{
		printf("and is 0\n");
	}
	else
	{
		printf("and is less than 6 and not 0\n");
	}

	return (0);
}

