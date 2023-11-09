#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: A pointer to a pointer to the head of the list.
 *
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *new_node;

	while (head)
	{
		new_node = head;
		head = head->next;
		free(new_node);
	}
}
