#include "lists.h"
/**
 * free_listint - function that frees a list_t list
 * @head: A pointer to a pointer to the head of the list.
 *
 */

void free_listint(listint_t *head)
{
	listint_t *last;

	while (head != NULL)
	{
		last = head;
		head = head->next;
		free(last);
	}
}
