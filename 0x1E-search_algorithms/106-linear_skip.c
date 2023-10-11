#include "search_algos.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located.
 *          value is not present in list or head is NULL -- return NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *jnode;

	if (list == NULL)
		return (NULL);

	for (node = jnode = list; jnode->next != NULL && jnode->n < value;)
	{
		node = jnode;
		if (jnode->express != NULL)
		{
			jnode = jnode->express;
			printf("Value checked at index [%ld] = [%d]\n",
					jnode->index, jnode->n);
		}
		else
		{
			while (jnode->next != NULL)
				jnode = jnode->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jnode->index);

	for (; node->index < jnode->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n",
				node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
