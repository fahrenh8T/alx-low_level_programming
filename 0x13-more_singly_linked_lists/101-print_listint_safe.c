#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * print_listint_safe - prints a liinked list even if it has a loop
 * @head: pointer to the head of the linked list
 *
 * Return: number of nodes in the linked list
*/
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *one = head;
	 const listint_t *two = head->next;
	size_t all = 0;

	if (head == NULL)
		exit(98);

	while (two != NULL && two < two->next)
	{
		printf("[%p]%d\n", (void *)one, one->n);
		one = one->next;
		two = two->next->next;
		all++;
	}
	printf("[%p]%d\n", (void *)one, one->n);
	all++;

	if (two != NULL)
	{
		printf("->[%p]%d\n", (void *)two, two->n);
		all++;
	}
	return (all);
}
