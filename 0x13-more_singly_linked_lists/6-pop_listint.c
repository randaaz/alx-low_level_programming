#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 *               and returns the head node’s data (n).
 * @head: A pointer to a pointer to the head of the list.
 *
 * Return: The (n) of the deleted head node, or 0 if the list is empty.
 */

int pop_listint(listint_t **head)
{
	int n;
	listint_t *last;

	if (*head == NULL)
	{
		return (0);
	}
	n = (*head)->n;
	last = *head;
	*head = (*head)->next;
	free(last);
	return (n);
}
