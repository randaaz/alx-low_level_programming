#include "search_algos.h"

/**
 * linear_skip - Perform linear skip search on a skip list.
 *
 * This function uses linear skip search to find
 * a specific value in a skip list.
 * It prints the checked values during the search process.
 *
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer to the node containing the value, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *g;

if (list == NULL)
return (NULL);

g = list;

do {
list = g;
g = g->express;
printf("Value checked at index ");
printf("[%d] = [%d]\n", (int)g->index, g->n);
} while (g->express && g->n < value);

if (g->express == NULL)
{
list = g;
while (g->next)
g = g->next;
}

printf("Value found between indexes ");
printf("[%d] and [%d]\n", (int)list->index, (int)g->index);

while (list != g->next)
{
printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
if (list->n == value)
return (list);
list = list->next;
}

return (NULL);
}
