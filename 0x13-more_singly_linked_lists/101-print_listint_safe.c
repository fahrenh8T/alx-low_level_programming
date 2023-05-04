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

	if (head == NULL)
		exit(98);

	while (two && two < one)
	{
		printf("[%p] %d\n", (void *)one, one->n);
		one = one->next;
		two = two->next;

		if (two && two < one)
			two = two->next;
	}

	if (two)
	{
		printf("[%p] %d\n", (void *)one, one->n);
		one = one->next;
		two = two->next;
		printf("-> [%p] %d\n", (void *)one, one->n);
		while (two && two >= head && two > one)
		{
			printf("[%p] %d\n", (void *)one, one->n);
			one = one->next;
			two = two->next;
		}
	}
	printf("[%p] %d\n", (void *)one, one->n);

	return (one - head + print_listint_safe(head));
}
