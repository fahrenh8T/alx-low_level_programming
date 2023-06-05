#include <stdio.h>

/**
*main - Entry point
*Program starts from first letter lowercase alphabet and loops from a-z
*resets first letter to uppercase and loops from A-Z
*Return: Always 0 (success)
*/
int main(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		putchar(letter);
		letter++;
	}

	letter = 'A';

	while (letter <= 'Z')
	{
		putchar(letter);
		letter++;
	}

	putchar('\n');

	return (0);
}
