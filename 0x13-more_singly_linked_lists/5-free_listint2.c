#include "lists.h"

/**
 * free_listint2 - function that frees a listint_t list
 * @head: A pointer to a pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	if (head == NULL || *head == NULL)
	{
		return;
	}

	listint_t *current = *head;
	listint_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}

	*head = NULL;
}
