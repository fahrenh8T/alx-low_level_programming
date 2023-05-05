#include "main.h"
/**
 * flip_bits- returns the number of bits you would need to flip
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = n ^ m;
	unsigned int total = 0;

	while (flip)
	{
		flip = flip & (flip - 1);
		total++;
	}
	return (total);
}
