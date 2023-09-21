#include "lists.h"
/**
 * add_node - function that adds a new node at the beginning of a list_t list
 * @head: A pointer to a pointer to the head of the list.
 * @str: The string to be stored in the new node.
 *
 * Return: The address of the new element, or NULL if it failed
 */

list_t *add_node(list_t **head, const char *str)
{
	int i = 0;
	int j = 0;
	list_t *new;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i])
	{
		i++;
	}
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	for (j = 0; j <= i; j++)
	{
		new->str[j] = str[j];
	}
	new->len = i;
	new->next = *head;
	*head = new;
	j++;
	return (new);
}
