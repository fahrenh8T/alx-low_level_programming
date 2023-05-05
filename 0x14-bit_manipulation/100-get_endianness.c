#include <stdio.h>
#include "main.h"
/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
*/
int get_endianness(void)
{
	unsigned int r = 1;
	char *w = (char *) &r;

	return (*w == 1);
}
