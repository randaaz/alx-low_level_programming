#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list..
 * @h: Is a pointer to a dlistint_t structure
 * Return: the number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t j = 0;

	while (h)
	{
		h = h->next;
		j++;
	}
	return (j);
}
