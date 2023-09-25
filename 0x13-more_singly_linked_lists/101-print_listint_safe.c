#include "lists.h"

/**
 * list - adds a new node to the list of visited nodes
 * @l: A pointer to the list of visited nodes
 * @lt: The size of the list
 * @new1: A pointer to the new node to add
 *
 * Return: A pointer to the updated list of visited nodes,
 * or exit with status 98 on failur.
 */

const listint_t **list(const listint_t **l, size_t lt, const listint_t *new1)
{
	const listint_t **new_l;
	size_t j;

	new_l = malloc(lt * sizeof(listint_t *));
	if (new_l == NULL)
	{
		free(l);
		exit(98);
	}
	for (j = 0; j < lt - 1; j++)
	{
		new_l[j] = l[j];
	}
	new_l[j] = new1;
	free(l);
	return (new_l);
}


/**
 * print_listint_safe - Prints the elements of a linked list safely
 * @head: A pointer to the head of the linked list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t j = 0, i;
	const listint_t **new1 = NULL;

	while (head != NULL)
	{
		for (i = 0; i < j; i++)
		{
			if (head == new1[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(new1);
				return (j);
			}
		}
		j++;
		new1 = list(new1, j, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(new1);
	return (j);
}
