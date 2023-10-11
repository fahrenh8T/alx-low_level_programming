#include "search_algos.h"
/**
 * search - searches for a value in an array of
 * integers using the Binary search algorithm
 * @array: pointer to the first element of the array to search
 * @size: number of elements in array
 * @value: value to search in
 *
 * Return: index of the number
 */

int search(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
		return ((int)half);

	if (value < array[half])
		return (search(array, half, value));

	half++;

	return (search(array + half, size - half, value) + half);
}

/**
 * binary_search - calls to binary_search to return
 * the index of the number
 * @array: pointer to the first element of the array to search
 * @size: number of elements in array
 * @value: value to search in
 *
 * Return: index where value is located. Not present or NULL return -1
 */

int binary_search(int *array, size_t size, int value)
{
	int indx;

	indx = search(array, size, value);

	if (indx >= 0 && array[indx] != value)
		return (-1);

	return (indx);
}