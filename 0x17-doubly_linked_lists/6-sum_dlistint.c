#include "lists.h"
/**
 * sum_dlistint -  returns sum of all the data (n) of dlistint_t
 * @head: pointer to the head of list
 *
 * Return: sum of the data ir 0 (empty)
*/
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *crrnt = head;

	while (crrnt != NULL)
	{
		sum += crrnt->n;
		crrnt = crrnt->next;
	}
	return (sum);
}
