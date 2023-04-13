#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * malloc_checked - allocates memory
 * @b: integer
 *
 * Return: pointer
*/
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
