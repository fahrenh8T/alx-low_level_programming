#include "search_algos.h"
#include <math.h>
/**
 * jump_list - searches for a value in a sorted list of integers
 * @list: pointer to the first node of the list to search
 * @size: number of nodes in array
 * @value: value to search for
 *
 * Return: index where value is located. Not present or NULL return -1
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, sizes;
	listint_t *node, *j_node;

	if (list == NULL || size == 0)
		return (NULL);

	step = 0;
	sizes = sqrt(size);

	for (node = j_node = list; j_node->index + 1 < size && j_node->n < value;)
	{
		node = j_node;

		for (step += sizes; j_node->index < step; j_node = j_node->next)
		{
			if (j_node->index + 1 == size)
				break;
		}

		printf("Value checked at index [%ld] = [%d]\n",
				j_node->index, j_node->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, j_node->index);

	for (; node->index < j_node->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n",
				node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
