#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: integer starting point
 * Return: 0
*/
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (int i = n; i <= 98; i++)
		{
			_putchar(i / 10 + 48);
			_putchar(i % 10 + 48);
			_putchar(44);
			_putchar(32);
		}
		for (int i = n; i > 98; i--)
		{
			_putchar(i / 10 + 48);
			_putchar(i % 10 + 48);
			_putchar(44);
			_putchar(32);
		}
	}
	_putchar(57);
	_putchar(56);
	_putchar('\n');
}
