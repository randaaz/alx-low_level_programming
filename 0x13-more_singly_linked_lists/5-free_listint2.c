#include "lists.h"

/**
 * free_listint2 - function that frees a listint_t list
 * @head: A pointer to a pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *last = *head;
	listint_t *temp;

	if (head == NULL || *head == NULL)
	{
		return;
	}
	while (last != NULL)
	{
		temp = last->next;
		free(temp);
		last = temp;
	}

	*head = NULL;
}
