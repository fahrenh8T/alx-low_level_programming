#include "lists.h"
/**
 * get_dnodeint_at_index - returns the nth node of dlistint
 * @head: pointer to the head of the list
 * @index: index of the node to return, starting from 0
 *
 * Return: node at the given index or NULL (not exist)
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *crrnt = head;
	unsigned int cnt = 0;

	while (crrnt != NULL)
	{
		if (cnt == index)
			return (crrnt);

		crrnt = crrnt->next;
		cnt++;
	}
	return (NULL);
}
