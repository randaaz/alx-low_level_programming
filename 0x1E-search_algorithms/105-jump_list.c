#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Perform jump search on a singly linked list.
 *
 * This function uses the jump search algorithm to find a specific value
 * in a singly linked list. It prints the checked values during the search
 * process.
 *
 * @list: Pointer to the head of the linked list.
 * @size: Number of elements in the linked list.
 * @value: The value to search for.
 *
 * Return: Pointer to the node containing the value, or NULL if not found.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
size_t index, i, j;
listint_t *pr;

if (list == NULL || size == 0)
return (NULL);

j = (size_t)sqrt((double)size);
index = 0;
i = 0;

do {
pr = list;
i++;
index = i * j;

while (list->next && list->index < index)
list = list->next;

if (list->next == NULL && index != list->index)
index = list->index;

printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);

} while (index < size && list->next && list->n < value);

printf("Value found between indexes ");
printf("[%d] and [%d]\n", (int)pr->index, (int)list->index);

for (; pr && pr->index <= list->index; pr = pr->next)
{
printf("Value checked at index [%d] = [%d]\n", (int)pr->index, pr->n);
if (pr->n == value)
return (pr);
}

return (NULL);
}
