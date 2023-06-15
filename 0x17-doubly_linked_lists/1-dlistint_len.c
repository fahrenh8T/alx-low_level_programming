#include "lists.h"
/**
 * dlistint_len - returns the number of elements in a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes in the list
*/
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *crrnt = h;
	size_t cnt = 0;

	while (crrnt != NULL)
	{
		cnt++;
		crrnt = crrnt->next;
	}
	return (cnt);
}
