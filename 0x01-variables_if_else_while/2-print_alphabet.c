#include <stdio.h>

/**
 * main - Entry point
 * Program starts with first alphabet and loops it through a-z
 * Return: Always 0 (success)
*/

int main(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
	putchar(letter);
	letter++;
	}
	putchar('\n');

	return (0);
}
