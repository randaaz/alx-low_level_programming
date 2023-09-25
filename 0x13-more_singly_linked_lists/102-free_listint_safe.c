#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The number of nodes that were freed.
 */

size_t free_listint_safe(listint_t **h)
{
	size_t i;
	listint_t *j, *ln;
	int l = 1;

	if (h == NULL || *h == NULL)
		return (0);
	ln = hit(*h);
	for (i = 0; (*h != ln || l) && *h != NULL; *h = j)
	{
		i++;
		j = (*h)->next;
		if (*h == ln && l)
		{
			if (ln == ln->next)
			{
				free(*h);
				break;
			}
			i++;
			j = j->next;
			free((*h)->next);
			l = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (i);
}

/**
 * hit - Finds the node at which a linked list has a cycle.
 * @head: A pointer to the head of the list.
 *
 * Return: The node where the cycle begins, or NULL if there is no cycle.
 */

listint_t *hit(listint_t *head)
{
	listint_t *new, *last;

	if (head == NULL)
		return (NULL);
	for (last = head->next; last != NULL; last = last->next)
	{
		if (last == last->next)
			return (last);
		for (new = head; new != last; new = new->next)
			if (new == last->next)
				return (last->next);
	}
	return (NULL);
}
