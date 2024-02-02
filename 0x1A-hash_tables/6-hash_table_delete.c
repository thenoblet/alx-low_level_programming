#include "hash_tables.h"
#include <stdlib.h>
/**
* free_list - Frees a linked list.
* @head: Pointer to the first element of the list to be free'd.
*/
void free_list(hash_node_t *head)
{
	hash_node_t *iterator;

	while (head)
	{
		iterator = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = iterator;
	}
}
/**
* hash_table_delete - Deletes a hash table.
* @ht: Hash table.
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
		if (ht->array[i])
			free_list(ht->array[i]);
	free(ht->array);
	free(ht);
}
