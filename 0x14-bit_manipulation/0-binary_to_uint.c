#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * binary_to_uint - converts a binary numberto an unsigned int
 * @b: pointer to a string of char 0 and 1
 *
 * Return: converted number or 0 if one or more chars in
 * string b that is not 0 or 1 or b is null
*/
unsigned int binary_to_uint(const char *b)
{
	unsigned int no = 0;
	int lnght = strlen(b);
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; i < lnght; i++)
	{
		if (b[i] == '0')
			no = no * 2;
		else if (b[i] == '1')
			no = no * 2 + 1;
		else
			return (0);
	}
	return (no);
}
