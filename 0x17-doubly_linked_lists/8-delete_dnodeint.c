#include "lists.h"

/**
 * delete_dnodeint_at_index - function that delete a
 * node at a given position.
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *currunt = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (currunt == NULL)
			return (-1);
		currunt = currunt->next;
	}
	if (currunt == *head)
	{
		*head = currunt->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
	}
	else
	{
		currunt->prev->next = currunt->next;
		if (currunt->next != NULL)
		{
			currunt->next->prev = currunt->prev;
		}
	}
	free(currunt);
	return (1);
}
