#include "lists.h"
/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: Number of nodes in the list
*/
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *crrnt = h;
	size_t cnt = 0;

	while (crrnt != NULL)
	{
		printf("%d\n", crrnt->n);
		crrnt = crrnt->next;
		cnt++;
	}
	return (cnt);
}
