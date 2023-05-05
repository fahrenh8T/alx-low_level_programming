#include <stdlib.h>
#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to be checked
 * @index: index of the bit to be returned
 *
 * Return: value of bit or -1 if error
*/
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int cast = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	if ((n & cast) != 0)
		return (1);
	else
		return (0);
}
