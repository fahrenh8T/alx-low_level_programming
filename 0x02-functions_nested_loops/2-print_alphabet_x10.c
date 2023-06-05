#include "main.h"
/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase
 * Return: Always 0 (success)
*/
void print_alphabet_x10(void)
{
	int a;
	int b;

	for (b = 1; a <= 10; a++)
	{
		for (a = 97; a <= 122; a++)
		{
			_putchar(b);
		}
		_putchar('\n');
	}
}
