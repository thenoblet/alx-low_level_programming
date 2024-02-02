#include "hash_tables.h"
#include <stdlib.h>
/**
* hash_table_create - Creates a hash table.
* @size: Size of the hash table.
* Return: The created hash table.
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	hash_node_t **array;

	if (size == 0)
		return (NULL);
	table = malloc(sizeof(hash_table_t));
	if (!table)
		return (NULL);
	table->size = size;
	array = calloc(size, sizeof(hash_node_t *));
	if (!array)
	{
		free(table);
		return (NULL);
	}
	table->array = array;
	return (table);
}
