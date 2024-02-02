#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
/**
* check_dups - Checks for existing nodes with a key in a hash table.
* @h: Head node.
* @key: Key for the new node.
* @value: Value for the new node.
* Return: 1 if dup found and updated or 0 otherwise.
*/
int check_dups(const hash_node_t *h, const char *key, const char *value)
{
	hash_node_t *hn = (hash_node_t *) h;

	while (hn)
	{
		if (!strcmp(hn->key, key))
		{
			free(hn->value);
			hn->value = strdup(value);
			return (1);
		}
		hn = hn->next;
	}
	return (0);
}
/**
* add_node - Adds a node at the beggining of a list.
* @head: Pointer to the current first element of the list.
* @key: Key to initialize the new element.
* @value: Value to initialize the new element.
* Return: Pointer to the new first element or 0 if it fails.
*/
hash_node_t *add_node(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(hash_node_t));
	if (!new)
		return (NULL);
	new->key = strdup(key);
	new->value = strdup(value);
	new->next = *head;
	*head = new;
	return (new);
}
/**
* hash_table_set - Adds or updates an element on a hash table.
* @ht: Hash table.
* @key: Key to initialize the new element.
* @value: Value to initialize the new element.
* Return: 1 on success, 0 on failure.
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;

	if (!ht || !key || !value || !strcmp(key, ""))
		return (0);
	index = key_index((unsigned const char *)key, ht->size);
	if (!check_dups(ht->array[index], key, value))
		if (!add_node(&(ht->array[index]), key, value))
			return (0);
	return (1);
}
