#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at
 * a specified index in a listint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to delete (starting from 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *last, *temp;
	unsigned int i = 0;

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	last = *head;
	while (i < index - 1 && last != NULL)
	{
		last = last->next;
		i++;
	}

	if (last == NULL || last->next == NULL)
	{
		return (-1);
	}

	temp = last->next;
	last->next = last->next->next;
	free(temp);
	return (1);
}
