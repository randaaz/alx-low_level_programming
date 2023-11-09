#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the ending of a dlistint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @n: The integer value to be stored in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *last_node = malloc(sizeof(dlistint_t)), *new_node;

	if (!head || !last_node)
	{
		return (last_node ? free(last_node), NULL : NULL);
	}
	last_node->n = n;
	last_node->prev = NULL;
	if (!*head)
	{
		last_node->prev = NULL;
		*head = last_node;
	}
	else
	{
		new_node = *head;
		while (new_node->next)
		{
			new_node = new_node->next;
		}
		new_node->next = last_node;
		last_node->prev = new_node;
	}
	return (last_node);
}
