#include "hash_tables.h"

/**
 * hash_table_create - Creates a new hash table with a given size.
 * @size: The size of the array for the hash table.
 *
 * Return: A pointer to the newly created hash table, or NULL if memory
 * allocation fails.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *new_table;

	new_table = malloc(sizeof(hash_table_t));
	if (!new_table)
	{
		return (NULL);
	}
	new_table->array = malloc(sizeof(hash_node_t *) * size);
	if (!new_table->array)
	{
		free(new_table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		new_table->array[i] = NULL;
	}
	new_table->size = size;
	return (new_table);
}
