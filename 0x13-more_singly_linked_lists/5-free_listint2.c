#include "lists.h"
/**
 * free_listint2 - function that frees a list_t list
 * @head: A pointer to a pointer to the head of the list.
 *
 */

void free_listint2(listint_t **head)
{
	if (*head == NULL)
	{
		return;
	}
	listint_t *last;

	while (*head != NULL)
	{
		last = *head;
		*head = (*head)->next;
		free(last);
	}
	*head = NULL;
}
