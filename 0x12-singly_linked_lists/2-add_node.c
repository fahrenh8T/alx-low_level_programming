#include "lists.h"
/**
 * add_node - adds a new node at beginning of list_t
 * @head: pointer  to a pointer to the first element of list_t
 * @str:string to be added new line
 *
 * Return: address of new element or NULL if failure
*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *added;
	size_t len = 0;

	added = malloc(sizeof(list_t));

	if (added == NULL)
		return (NULL);

	added->str = strdup(str);

	if (added->str == NULL)
	{
		free(added);
		return (NULL);
	}
	while (str[len])
		len++;

	added->len = len;
	added->next = *head;
	*head = added;

	return (added);
}
