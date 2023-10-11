#include "search_algos.h"
/**
 * rec_search - searches for a value in an array of integers using
 * 				the Binary search algorithm
 * @array: pointer to the first element of the array to search
 * @size: number of elements in array
 * @value: value to search in
 *
 * Return: index where value is located. Not present or NULL return -1
 */

int search(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t indx;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (indx = 0; indx < size; indx++)
		printf("%s %d", (indx == 0) ? ":" : ",", array[indx]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
	{
		if (half > 0)
			return (search(array, half + 1, value));
		return ((int)half);
	}

	if (value < array[half])
		return (search(array, half + 1, value));

	half++;
	return (search(array + half, size - half, value) + half);
}


/**
 * advanced_binary - calls to rec_search to return the index of the
 * 					 number
 * @array: pointer to the first element of the array to search
 * @size: number of elements in array
 * @value: value to search in
 *
 * Return: index where value is located. Not present or NULL return -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
