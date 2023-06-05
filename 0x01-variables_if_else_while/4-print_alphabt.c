#include <stdio.h>

/**
* main - Entry point
* program all the alphabets except 'e' and 'q'
* Return: Always 0 (success)
*/
int main(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		if (letter != 'e' && letter != 'q')
		{
			putchar(letter);
		}

	letter++;
	}

	putchar('\n');

	return (0);
}
