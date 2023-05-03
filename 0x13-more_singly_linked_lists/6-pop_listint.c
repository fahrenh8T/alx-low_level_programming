#include <stdlib.h>
#include "lists.h"
/**
 * pop_listint - deletes the head node of of the linked list
 * @head: double pointer to the head of the linked list
 *
 * Return: data of head node or 0 if empty
*/
int pop_listint(listint_t **head)
{
	int value;
	listint_t *tmp;

	if (*head == NULL)
		return (0);

	value = (*head)->n;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);

	return (value);
}
