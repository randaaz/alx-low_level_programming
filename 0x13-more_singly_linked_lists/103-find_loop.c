#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *new = head, *last = head;

	while (new != NULL && last != NULL && last->next != NULL)
	{
		new = new->next;
		last = last->next;
		last = last->next;
		if (new == last)
		{
			new = head;

			while (new != last)
			{
				new = new->next;
				last = last->next;
			}

			return (new);
		}
	}

	return (NULL);
}

