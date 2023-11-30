#include "hash_tables.h"

/**
 * shash_table_create - Creates a new sorted hash table with a specified size.
 * @size: Unsigned long integer representing the size of the hash table.
 *
 * Return: A pointer to the newly created sorted hash table (shash_table_t).
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sh;
	unsigned long int j;

	sh = malloc(sizeof(shash_table_t));
	if (sh == NULL)
		return (NULL);
	sh->size = size;
	sh->shead = NULL;
	sh->stail = NULL;
	sh->array = malloc(sizeof(shash_node_t) * size);
	if (sh->array == NULL)
	{
		free(sh);
		return (NULL);
	}

	for (j = 0; j < size; j++)
	{
		sh->array[j] = NULL;
	}
	return (sh);
}

/**
 * shash_table_set - Adds or updates a key-value pair in the sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: A string representing the key.
 * @value: A string representing the value.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int ix;
	char *nv;
	shash_node_t *shnode, *temp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
			key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	ix = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[ix];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			nv = strdup(value);
			if (nv == NULL)
				return (0);
			free(temp->value);
			temp->value = nv;
			return (1);
		}
		temp = temp->next;
	}
	shnode = make_a_shnode(key, value);
	if (shnode == NULL)
		return (0);
	shnode->next = ht->array[ix];
	ht->array[ix] = shnode;
	add_to_sorted_list(ht, shnode);
	return (1);
}
/**
 * shash_table_get - Retrieves the value associated with a given key.
 * @ht: A pointer to the sorted hash table.
 * @key: A string representing the key.
 *
 * Return: The value associated with the key, or NULL if the key is not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int ix;
	shash_node_t *current;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
			key == NULL || strlen(key) == 0)
		return (NULL);

	ix = key_index((const unsigned char *)key, ht->size);
	current = ht->array[ix];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	return (NULL);
}

/**
 * make_a_shnode - Creates a new sorted hash node with the given key and value.
 * @key: A string representing the key of the hash node.
 * @value: A string representing the value associated with the key.
 *
 * Return: A pointer to the newly created sorted hash node (shash_node_t).
 */
shash_node_t *make_a_shnode(const char *key, const char *value)
{
	shash_node_t *shnode;

	shnode = malloc(sizeof(shash_node_t));
	if (shnode == NULL)
		return (NULL);

	shnode->key = strdup(key);
	if (shnode->key == NULL)
	{
		free(shnode);
		return (NULL);
	}
	shnode->value = strdup(value);
	if (shnode->value == NULL)
	{
		free(shnode->key);
		free(shnode);
		return (NULL);
	}

	shnode->next = shnode->snext = shnode->sprev = NULL;
	return (shnode);
}

/**
 * shash_table_print - Prints key-value pairs in ascending order of keys.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	char f = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	current = ht->shead;
	while (current != NULL)
	{
		if (f == 1)
		{
			printf(", ");
		}
		printf("'%s': '%s'", current->key, current->value);
		f = 1;
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints key-value pairs in descending order of keys.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	char f;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	current = ht->stail;
	while (current != NULL)
	{
		if (f == 1)
		{
			printf(", ");
		}
		printf("'%s': '%s'", current->key, current->value);
		f = 1;
		current = current->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - Deletes the entire sorted hash table, freeing memory.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int j;
	shash_node_t *current;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	for (j = 0; j < ht->size; ++j)
	{
		while (ht->array[j] != NULL)
		{
			current = ht->array[j]->next;
			free(ht->array[j]->key);
			free(ht->array[j]->value);
			free(ht->array[j]);
			ht->array[j] = current;
		}
	}

	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}

/**
 * add_to_sorted_list - Adds a sorted hash node
 * to the doubly linked list for sorting.
 * @t: A pointer to the sorted hash table.
 * @n: A pointer to the sorted hash node to be added.
 */

void add_to_sorted_list(shash_table_t *t, shash_node_t *n)
{
	shash_node_t *current;

	if (t->shead == NULL && t->stail == NULL)
	{
		t->shead = t->stail = n;
		return;
	}
	current = t->shead;
	while (current != NULL)
	{
		if (strcmp(n->key, current->key) < 0)
		{
			n->snext = current;
			n->sprev = current->sprev;
			current->sprev = n;
			if (n->sprev != NULL)
				n->sprev->snext = n;
			else
				t->shead = n;
			return;
		}
		current = current->snext;
	}
	n->sprev = t->stail;
	t->stail->snext = n;
	t->stail = n;
}
