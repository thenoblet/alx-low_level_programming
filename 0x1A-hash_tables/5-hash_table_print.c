#include "hash_tables.h"
#include <stdio.h>
/**
* print_list - prints all the elements of a linked list.
* @h: List to print.
* Return: Number of nodes of the list.
*/
size_t print_list(const hash_node_t *h)
{
	int counter = 0;

	while (h)
	{
		if (counter)
			printf(", ");
		printf("\'%s\': \'%s\'", h->key, h->value);
		h = h->next;
		counter++;
	}
	return (counter);
}
/**
* hash_table_print - Prints a hash table.
* @ht: Hash table.
*/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	char found = 0;

	if (ht)
	{
		putchar('{');
		for (i = 0; i < ht->size; i++)
			if (ht->array[i])
			{
				if (found)
					printf(", ");
				found = 1;
				print_list(ht->array[i]);
			}
		puts("}");
	}
}
