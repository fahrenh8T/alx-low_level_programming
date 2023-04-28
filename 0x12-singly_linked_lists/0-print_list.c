#include "lists.h"
/**
 * print_list - function that prints all the elements in list_t
 * @h: linked list node
 *
 * Return: number of nodes
*/
size_t print_list(const list_t *h)
{
	size_t cnt = 0;

	while (h != NULL)
	{
		if (h->str != NULL)
			printf("[%d]%s\n", h->len, h->str);
		else
			printf("[0] (nil)\n");

		h = h->next;
		cnt++;
	}
	return (cnt);
}
