#include "lists.h"
/**
 * insert_dnodeint_at_index - inserts a new node at a given position in list
 * @h: double pointer to the head of the list
 * @idx: index of the position to insert the new node, starting from 0
 * @n: data to store in new node
 *
 * Return: address of the new node or NULL (failure)
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *crrnt = *h;
	unsigned int cnt = 0;
	dlistint_t *nnode = malloc(sizeof(dlistint_t));

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	if (nnode == NULL)
		return (NULL);

	while (crrnt != NULL)
	{
		if (cnt == idx - 1)
		{
			nnode->n = n;
			nnode->prev = crrnt;
			nnode->next = crrnt->next;

			if (crrnt->next != NULL)
				crrnt->next->prev = nnode;

			crrnt->next = nnode;
			return (nnode);
		}

		crrnt = crrnt->next;
		cnt++;
	}

	free(nnode);
	return (NULL);
}
