#include <stdlib.h>
#include "lists.h"
/**
 * delete_nodeint_at_index - deletes node at a given position
 * @head: double pointer to the head of the linked list
 * @index: index of the node to be deleted
 *
 * Return: 1 if successful -1 if failure
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;

	listint_t *last = *head;
	listint_t *node = (*head)->next;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		listint_t *tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	for (i = 1; i < index; i++)
	{
		if (node == NULL)
			return (-1);
		last = node;
		node = node->next;
	}

	last->next = node->next;
	free(node);
	return (1);
}
