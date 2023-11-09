#include "lists.h"

/**
 * get_dnodeint_at_index -  function that returns the nth
 * node of a dlistint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 * @index: the index of the element
 *
 * Return: the node at index or NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
{
	unsigned int i = 0;

	while (head)
	{
		if (i == index)
		{
			return (head);
		}
		head = head->next;
		i++;
	}
	return (NULL);
}
