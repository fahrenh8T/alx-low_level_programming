#include <stdlib.h>
#include "lists.h"
/**
 * get_nodeint_at_index - returns the nth node of the linked list
 * @head: pointer to the head of the linked list
 * @index: index of the node to be returned
 *
 * Return: nth node or null if empty
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int ind;

	for (ind = 0; head != NULL && ind < index; ind++)
	{
		head = head->next;
	}
	return (head);
}
