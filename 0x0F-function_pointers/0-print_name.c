#include "function_pointers.h"
/**
 * print_name - function that prints a name
 * @name: element's name
 * @f: pointer
*/
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
