#include "hash_tables.h"

/**
 * make_a_new_node - Creates a new hash node.
 * @key: The key for the new node.
 * @value: The value for the new node.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */

hash_node_t *make_a_new_node(const char *key, const char *value)
{
	hash_node_t *nd;

	nd = malloc(sizeof(hash_node_t));
	if (!nd)
	{
		return (NULL);
	}
	nd->key = strdup(key);
	if (!nd->key)
	{
		free(nd);
		return (NULL);
	}
	nd->value = strdup(value);
	if (!nd->value)
	{
		free(nd->key);
		free(nd);
		return (NULL);
	}
	nd->next = NULL;
	return (nd);
}

/**
 * hash_table_set - Adds or updates an element in the hash table.
 * @ht: The hash table to modify.
 * @key: The key to add or update.
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;

	if (!ht || ht->size == 0 || !value ||
			!key || strlen(key) == 0 || !ht->array)
	{
		return (0);
	}
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (!current->value)
			{
				return (0);
			}
			return (1);
		}
		current = current->next;
	}
	new_node = make_a_new_node(key, value);
	if (!new_node)
	{
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
