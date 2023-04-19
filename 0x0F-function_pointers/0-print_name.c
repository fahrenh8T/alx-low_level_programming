#include "function_pointers.h"
#include <stdio.h>
#include <stddef.h>
/**
 * print_name - function that prints a name
 * @name: element's name
 * @f: pointer
*/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
