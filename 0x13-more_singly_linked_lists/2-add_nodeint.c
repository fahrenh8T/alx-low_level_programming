#include <stdlib.h>
#include "lists.h"
/**
 * add_nodeint - adds a new node at the beginning of the linked list
 * @head: double pointer to the head of the list
 * @n: data inside new node
 *
 * Return: address of new element or null if failure
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *nnode = malloc(sizeof(listint_t));

	if (nnode == NULL)
		return (NULL);

	nnode->n = n;
	nnode->next = *head;
	*head = nnode;

	return (nnode);
}
