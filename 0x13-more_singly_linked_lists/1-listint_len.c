#include <stdlib.h>
#include "lists.h"
/**
 * listint_len - returns the number of elements in a linked list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
*/
size_t listint_len(const listint_t *h)
{
	size_t all = 0;

	while (h != NULL)
	{
		all++;
		h = h->next;
	}
	return (all);
}
