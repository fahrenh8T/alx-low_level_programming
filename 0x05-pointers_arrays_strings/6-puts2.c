#include "main.h"
/**
 * puts2 - prints every character of a string
 * @str: pointer for the string
 * Return: 0
*/
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
