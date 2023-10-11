#include "search_algos.h"
#include <math.h>
/**
 * jump_search - searches for a value in an array of
 * integers using the Jump search algorithm
 *
 * @array: pointer to the first element of the array to search
 * @size: number of elements in array
 * @value: value to search for.
 *
 * Return: index where value is located. Not present or NULL return -1
 */

int jump_search(int *array, size_t size, int value)
{
	int crrnt, blck_sz, step, prev;

	if (array == NULL || size == 0)
		return (-1);

	blck_sz = (int)sqrt((double)size);
	step = 0;
	prev = crrnt = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", crrnt, array[crrnt]);

		if (array[crrnt] == value)
			return (crrnt);
		step++;
		prev = crrnt;
		crrnt = step * blck_sz;
	} while (crrnt < (int)size && array[crrnt] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev, crrnt);

	for (; prev <= crrnt && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}
