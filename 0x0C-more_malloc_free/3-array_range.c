#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * array_range -creates and array of integers
 * @min: minimum value
 * @max:maximum value
 *
 * Return: pointer or NULL
*/
int *array_range(int min, int max)
{
	int *s;
	int size, i;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	s = malloc(size * sizeof(int));

	if (s == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		s[i] = min;
		min++;
	}
	return (s);
}
