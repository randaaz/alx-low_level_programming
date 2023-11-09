#include "lists.h"

/**
 * sum_dlistint - function that returns the sum of all the
 * data (n) of a dlistint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 *
 * Return: sum of all the data (n) of a dlistint_t linked list.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum_of_all_the_data = 0;

	while (head)
	{
		sum_of_all_the_data += head->n;
		head = head->next;

	}
	return (sum_of_all_the_data);
}
