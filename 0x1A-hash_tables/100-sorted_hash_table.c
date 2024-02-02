#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
* shash_table_create - Creates a sorted hash table.
* @size: Size of the table.
* Return: The created table.
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	shash_node_t **array;

	if (size == 0)
		return (NULL);
	table = malloc(sizeof(shash_table_t));
	if (!table)
		return (NULL);
	table->size = size;
	array = calloc(size, sizeof(shash_node_t *));
	if (!array)
	{
		free(table);
		return (NULL);
	}
	table->array = array;
	table->shead = NULL;
	table->stail = NULL;
	return (table);
}
/**
* scheck_dups - Checks for existing nodes with a key in a sorted hash table.
* @h: Head node.
* @key: Key for the new node.
* @value: Value for the new node.
* Return: 1 if dup found and updated or 0 otherwise.
*/
int scheck_dups(const shash_node_t *h, const char *key, const char *value)
{
	shash_node_t *hn = (shash_node_t *) h;

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
* sadd_node - Adds a node at the beggining of a list.
* @head: Pointer to the current first element of the list.
* @key: Key to initialize the new element.
* @value: Value to initialize the new element.
* Return: Pointer to the new first element or 0 if it fails.
*/
shash_node_t *sadd_node(shash_node_t **head, const char *key,
const char *value)
{
	shash_node_t *new;

	if (!head || !key || !strcmp(key, ""))
		return (NULL);
	new = malloc(sizeof(shash_node_t));
	if (!new)
		return (NULL);
	new->key = strdup(key);
	new->value = strdup(value);
	new->next = *head;
	new->sprev = NULL;
	new->snext = NULL;
	*head = new;
	return (new);
}
/**
* shash_table_set - Adds or updates an element on a hash table.
* @ht: Hash table.
* @key: Key to initialize the new element.
* @value: Value to initialize the new element.
* Return: 1 on success, 0 on failure.
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *sorted, *iterator;

	if (!ht || !key || !value || !strcmp(key, ""))
		return (0);
	index = key_index((unsigned const char *)key, ht->size);
	if (!scheck_dups(ht->array[index], key, value))
	{
		sorted = sadd_node(&(ht->array[index]), key, value);
		if (!sorted)
			return (0);
	}
	else
		return (1);
	if (!(ht->shead))
		ht->shead = sorted, ht->stail = sorted;
	else
	{
		for (iterator = ht->shead; iterator; iterator = iterator->snext)
			if (strcmp(sorted->key, iterator->key) <= 0)
			{
				sorted->snext = iterator;
				sorted->sprev = iterator->sprev;
				if (iterator->sprev)
					iterator->sprev->snext = sorted;
				else
					ht->shead = sorted;
				iterator->sprev = sorted;
				break;
			}
		if (!iterator)
		{
			ht->stail->snext = sorted;
			sorted->sprev = ht->stail;
			ht->stail = sorted;
		}
	}
	return (1);
}
/**
* shash_table_get - Gets an element by key on a sorted hash table.
* @ht: Hash table.
* @key: Key used to search.
* Return: Value found or NULL if not found.
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *iterator;

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
/**
* shash_table_print - Prints a sorted hash table.
* @ht: Sorted hash table.
*/
void shash_table_print(const shash_table_t *ht)
{
	int counter = 0;
	shash_node_t *h;

	if (ht)
	{
		h = ht->shead;
		putchar('{');
		while (h)
		{
			if (counter)
				printf(", ");
			printf("\'%s\': \'%s\'", h->key, h->value);
			h = h->snext;
			counter++;
		}
		puts("}");
	}
}
/**
* shash_table_print_rev - Prints a sorted hash table in reverse order.
* @ht: sorted hash table.
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	int counter = 0;
	shash_node_t *h;

	if (ht)
	{
		h = ht->stail;
		putchar('{');
		while (h)
		{
			if (counter)
				printf(", ");
			printf("\'%s\': \'%s\'", h->key, h->value);
			h = h->sprev;
			counter++;
		}
		puts("}");
	}
}
/**
* shash_table_delete - Deletes a sorted hash table.
* @ht: Sorted hash table.
*/
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *iterator = ht->shead;

	while (ht->shead)
	{
		iterator = ht->shead->snext;
		free(ht->shead->key);
		free(ht->shead->value);
		free(ht->shead);
		ht->shead = iterator;
	}
	free(ht->array);
	free(ht);
}
