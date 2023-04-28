#include "lists.h"
/**
 * add_node_end - adds new node at end of the list_t
 * @head: pointer to the head of the list
 * @str: string
 *
 * Return: address of new element or NULL if failure
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *current;

	if (!head || !str)
		return (NULL);

	new = malloc(sizeof(list_t));

	if (!new)
		return (NULL);

	new->str = strdup(str);

	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	current = *head;

	while (current->next != NULL)
		current = current->next;

	current->next = new;

	return (new);
}
