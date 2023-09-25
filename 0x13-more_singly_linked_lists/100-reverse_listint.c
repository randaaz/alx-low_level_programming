#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *pre = NULL;
	listint_t *last = *head;
	listint_t *next;

	while (last)
	{
		next = last->next;
		last->next = pre;
		pre = last;
		last = next;
	}

	*head = pre;
	return (pre);
}
