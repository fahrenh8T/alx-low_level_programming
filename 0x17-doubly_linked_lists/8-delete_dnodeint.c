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
	dlistint_t *crrnt = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (crrnt == NULL)
			return (-1);
		crrnt = crrnt->next;
	}

	if (crrnt == *head)
	{
		*head = crrnt->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		crrnt->prev->next = crrnt->next;
		if (crrnt->next != NULL)
			crrnt->next->prev = crrnt->prev;
	}

	free(crrnt);

	return (1);
}
