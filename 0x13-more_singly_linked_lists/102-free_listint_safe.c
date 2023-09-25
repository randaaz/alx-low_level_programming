#include "lists.h"

/**
 * free_listint_safe -  frees a listint_t list
 * @h: Pointer to a pointer to the head of the list.
 *
 * Return: the size of the list that was free’d
 */


size_t free_listint_safe(listint_t **h)
{
	listint_t *last = *h, *temp;
	size_t i = 0;

	while (last != NULL)
	{
		temp = last->next;
		free(last);
		i++;
		if (last <= temp)
		{
			*h = NULL;
			break;
		}
		last = temp;
	}

	*h = NULL;
	return (i);
}
