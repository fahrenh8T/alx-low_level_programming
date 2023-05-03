#include <stdlib.h>
#include "lists.h"
/**
 * add_nodeint_end - adds new node at the end of linked list
 * @head: double pointer to the head of the list
 * @n: data inside new node
 *
 * Return: address of new element or null if failure
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *nnode = malloc(sizeof(listint_t));
	listint_t *lnode = *head;

	if (nnode == NULL)
	{
		return (NULL);
	}

	nnode->n = n;
	nnode->next = NULL;

	if (lnode == NULL)
	{
		*head = nnode;
	}
	else
	{
		while (lnode->next != NULL)
		{
			lnode = lnode->next;
		}
		lnode->next = nnode;
	}
	return (nnode);
}
