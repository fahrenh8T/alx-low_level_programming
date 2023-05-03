#include <stdlib.h>
#include "lists.h"
/**
 * free_listint2 - frees linked list and sets head to null
 * @head: double pointer to the head of the linked list
 *
 * Return: void
*/
void free_listint2(listint_t **head)
{
	listint_t *node;

	while (*head != NULL && head != NULL)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
	}
	
	*head = NULL;
}
