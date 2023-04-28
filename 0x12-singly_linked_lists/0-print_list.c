#include "lists.h"
/**
 * print_list - function that prints all the elements in list_t
 * @lst: linked list node
 *
 * Return: number of nodes
*/
size_t print_list(const list_t *lst)
{
	size_t cnt = 0;

	while (lst != NULL)
	{
		if (lst->str != NULL)
			printf("[%d]%s\n", lst->len, lst->str);
		else
			printf("[0] (nil)\n");

		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
