#include "lists.h"

/**
 * listint_len - prints the elements of a linked list_t list
 * @h: A pointer to the head of the list
 *
 * Return: The number of elements in a linked list_t list
 */

size_t listint_len(const listint_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	return (i);
}
