#include "lists.h"
/**
 * free_listint2 - function that frees a list_t list
 * @head: A pointer to a pointer to the head of the list.
 *
 */

void free_listint2(listint_t **head)
{
	listint_t *last;

	if (head == NULL || *head == NULL)
	{
		return;
	}

	while (*head != NULL)
	{
		last = *head;
		*head = (*head)->next;
		free(last);
	}
	*head = NULL;
}
