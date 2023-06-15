#include "lists.h"
/**
 * free_dlistint - frees a dlistint
 * @head: pointer to the head of the list
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *crrnt;

	while (head != NULL)
	{
		crrnt = head;
		head = head->next;
		free(crrnt);
	}
}
