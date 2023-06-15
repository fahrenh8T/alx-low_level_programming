#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes the node at a given position
 * @head: double pointer to the head of the list
 * @index: index of the node to delete starting from 0
 *
 * Return: 1 (success) -1 (failure)
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *crrnt;
	unsigned int cnt;

	if (head == NULL || *head == NULL)
		return (-1);

	crrnt = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(crrnt);
		return (1);
	}

	cnt = 0;
	while (crrnt != NULL)
	{
		if (cnt == index)
		{
			crrnt->prev->next = crrnt->next;
			if (crrnt->next != NULL)
				crrnt->next->prev = crrnt->prev;
			free(crrnt);
			return (1);
		}

		crrnt = crrnt->next;
		cnt++;
	}
	return (-1);
}
