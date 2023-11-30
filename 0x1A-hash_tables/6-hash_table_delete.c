#include "hash_tables.h"
/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to the hash table to be deleted.
 *
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current, *tmp;

	if (!ht || !ht->array)
	{
		return;
	}
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current)
		{
			current = current->next;
			tmp = current;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
