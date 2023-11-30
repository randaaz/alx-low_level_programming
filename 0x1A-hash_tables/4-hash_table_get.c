#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a
 * given key in a hash table.
 * @ht: A pointer to the hash table to search.
 * @key: The key to look up in the hash table.
 *
 * Return: If the key is found, the function
 * returns the corresponding value.
 * If the key is not found or the hash table is
 * invalid, the function returns NULL.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (!ht || !key)
	{
		return (NULL);
	}
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			return (current->value);
		}
		current = current->next;
	}
	return (NULL);
}
