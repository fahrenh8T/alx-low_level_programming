#include "main.h"
/**
 * _islower -shows 1 if input is lowercase. 0 if otherwise
 * @c: the character in ASCII table
 * Return: 1 for lowercase. 0 if otherwise.
*/
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
