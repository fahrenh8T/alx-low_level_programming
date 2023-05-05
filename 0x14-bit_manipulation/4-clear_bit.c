#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the number to be modified
 * @index: index of the bit
 *
 * Return: 1 success or -1 error
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int cast = 1;
	unsigned int tmp = index;

	if (index > 63)
		return (-1);

	while (tmp > 0)
	{
		cast = cast * 2;
		tmp--;
	}

	if ((*n >> index) & 1)
		*n -= cast;

	return (1);
}
