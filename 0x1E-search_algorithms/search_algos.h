#ifndef _SORTING_ALGOS_H_
#define _SORTING_ALGOS_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - A structure representing a node in a singly linked list.
 * @n: The integer value stored in the node.
 * @index: The index of the node in the linked list.
 * @next: Pointer to the next node in the linked list.
 */
typedef struct listint_s
{
int n;
size_t index;
struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - A structure representing a node in a skip list.
 * @n: The integer value stored in the node.
 * @index: The index of the node in the skip list.
 * @next: Pointer to the next node in the skip list.
 * @express: Pointer to the express lane in the skip list.
 */
typedef struct skiplist_s
{
int n;
size_t index;
struct skiplist_s *next;
struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
