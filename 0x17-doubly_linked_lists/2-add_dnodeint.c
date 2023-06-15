#include "lists.h"
/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t
 * @head: double pointer to the head of the list
 * @n: data to store in the new node
 *
 * Return: address of the new node or NULL (failure)
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *nnode = malloc(sizeof(dlistint_t));

	if (nnode == NULL)
		return (NULL);

	nnode->n = n;
	nnode->prev = NULL;
	nnode->next = *head;

	if (*head != NULL)
		(*head)->prev = nnode;

	*head = nnode;

	return (nnode);
}
