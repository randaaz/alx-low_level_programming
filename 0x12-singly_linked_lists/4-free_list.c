#include "lists.h"
/**
 * free_list - function that frees a list_t list
 * @head: A pointer to a pointer to the head of the list.
 *
 */

void free_list(list_t *head)
{
	list_t *last;

	while (head != NULL)
	{
		last = head;
		head = head->next;
		free(last->str);
		free(last);
	}
}
