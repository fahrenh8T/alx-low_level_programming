#include <stdlib.h>
#include "lists.h"
/**
 * insert_nodeint_at_index - inserts a new node at given position
 * @head: double pointer to the head of the linked list
 * @idx: index of the list where the new node is added
 * @n: data inside new node
 *
 * Return: address of new node of null if failure
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *nnode, *tmp;
	unsigned int i;

	nnode = malloc(sizeof(listint_t));
	nnode->n = n;
	nnode->next = NULL;
	tmp = *head;

	if (head == NULL)
		return (NULL);

	if  (nnode == NULL)
		return (NULL);

	if (idx == 0)
	{
		nnode->next = *head;
		*head = nnode;
		return (nnode);
	}

	for (i = 0; i < idx - 1 && tmp != NULL; i++)
		tmp = tmp->next;

	if (tmp == NULL)
	{
		free(nnode);
		return (NULL);
	}
	nnode->next = tmp->next;
	tmp->next = nnode;

	return (nnode);
}
