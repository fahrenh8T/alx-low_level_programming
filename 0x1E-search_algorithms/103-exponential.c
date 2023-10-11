#include "search_algos.h"
/**
  * _binary_search - searches for a value in a sorted array of integers
  *                  using binary search.
  * @array: pointer to the first element of the array to search
  * @left: The starting index of the [sub]array to search.
  * @right: The ending index of the [sub]array to search.
  * @value: value to search in
  *
  * Return: index where value is located. Not present or NULL return -1
  */

int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t indx;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (indx = left; indx < right; indx++)
			printf("%d, ", array[indx]);
		printf("%d\n", array[indx]);

		indx = left + (right - left) / 2;
		if (array[indx] == value)
			return (indx);
		if (array[indx] > value)
			right = indx - 1;
		else
			left = indx + 1;
	}

	return (-1);
}

/**
  * exponential_search - searches for a value in a sorted array of integers
  *                      using exponential search.
  * @array: pointer to the first element of the array to search
  * @size: number of elements in array
  * @value: value to search in
  *
  * Return: index where value is located. Not present or NULL return -1
  */

int exponential_search(int *array, size_t size, int value)
{
	size_t indx = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (indx = 1; indx < size && array[indx] <= value; indx = indx * 2)
			printf("Value checked array[%ld] = [%d]\n", indx, array[indx]);
	}

	right = indx < size ? indx : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", indx / 2, right);
	return (_binary_search(array, indx / 2, right, value));
}
