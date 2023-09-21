#include "lists.h"

/**
 * print_list - Prints the elements of a linked list_t list
 * @h: A pointer to the head of the list
 *
 * Return: The number of elements in a linked list_t list
 */

size_t print_list(const list_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{

			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		i++;
		h = h->next;
	}
	return (i);
}
