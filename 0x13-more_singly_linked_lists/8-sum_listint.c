#include <stdlib.h>
#include "lists.h"
/**
 * sum_listint - returns the sum of all the data (n)
 * @head: pointer to the head of the linked list
 *
 * Return: sum of all the data or 0 if list is empty
*/
int sum_listint(listint_t *head)
{
	int ttl = 0;

	while (head != NULL)
	{
		ttl += head->n;
		head = head->next;
	}
	return (ttl);
}
