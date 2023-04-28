#include "lists.h"
/**
 * free_list - frees a list_t
 * @head: pointer to the head of list_t
 *
 * Return: void
*/
void free_list(list_t *head)
{
	list_t *current, *drop;

	current = head;

	while (current != NULL)
	{
		drop = current;
		current = current->next;
		free(drop->str);
		free(drop);
	}
}
