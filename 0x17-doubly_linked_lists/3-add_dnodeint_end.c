#include "lists.h"
/**
 * add_dnodeint_end - adds a new node at the end of dlistint_t
 * @head: double pointer to the head of the list
 * @n: data to store in the new node
 *
 * Return: address of the new node or NULL (failure)
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nnode = malloc(sizeof(dlistint_t));
	dlistint_t *crrnt;

	if (nnode == NULL)
		return (NULL);

	nnode->n = n;
	nnode->next = NULL;

	if (*head == NULL)
	{
		nnode->prev = NULL;
		*head = nnode;
	}
	else
	{
		crrnt = *head;
		while (crrnt->next != NULL)
			crrnt = crrnt->next;

		crrnt->next = nnode;
		nnode->prev = crrnt;
	}
	return (nnode);
}
