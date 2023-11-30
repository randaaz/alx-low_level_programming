#include "hash_tables.h"
/**
 * key_index - Calculates the index of a key in a hash table array.
 * @key: The key to be hashed and indexed.
 * @size: The size of the array for the hash table.
 *
 * Return: The index in the array where the key should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
