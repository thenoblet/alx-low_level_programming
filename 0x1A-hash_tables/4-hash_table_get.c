#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
* hash_table_get - Gets an element by key on a hash table.
* @ht: Hash table.
* @key: Key used to search.
* Return: Value found or NULL if not found.
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *iterator;

	if (!ht || !key || !strcmp(key, ""))
		return (NULL);
	index = key_index((unsigned const char *)key, ht->size);
	iterator = ht->array[index];
	while (iterator)
	{
		if (!strcmp(iterator->key, key))
			return (iterator->value);
		iterator = iterator->next;
	}
	return (NULL);
}
