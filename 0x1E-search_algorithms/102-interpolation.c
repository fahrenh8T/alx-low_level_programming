#include "search_algos.h"
/**
 * interpolation_search - searches for a value in an array of
 * integers using the Interpolation search algorithm
 * @array: pointer to the first element of the array to search
 * @size: number of elements in array
 * @value: value to search in
 *
 * Return: index where value is located. Not present or NULL return -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t postn, low, high;
	double intp_factor;

	if (array == NULL)
		return (-1);

	low = 0;
	high = size - 1;

	while (size)
	{
		intp_factor = (double)(high - low) / (array[high] - array[low]) * (value - array[low]);
		postn = (size_t)(low + intp_factor);
		printf("Value checked array[%d]", (int)postn);

		if (postn >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[postn]);
		}

		if (array[postn] == value)
			return ((int)postn);

		if (array[postn] < value)
			low = postn + 1;
		else
			high = postn - 1;

		if (low == high)
			break;
	}

	return (-1);
}