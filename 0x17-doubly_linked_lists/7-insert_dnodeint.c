#include "lists.h"

/**
 * insert_dnodeint_at_index - function that inserts a
 * new node at a given position.
 * @h: A pointer to a pointer to the head of the list.
 * @idx: The index
 * @n: The integer value to be stored in the new node.
 * Return: new node at a given position or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *currunt = *h, *new_node;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		currunt = currunt->next;
		if (currunt == NULL)
			return (NULL);
	}
	if (currunt->next == NULL)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = currunt;
	new_node->next = currunt->next;
	currunt->next->prev = new_node;
	currunt->next = new_node;

	return (new_node);
}
