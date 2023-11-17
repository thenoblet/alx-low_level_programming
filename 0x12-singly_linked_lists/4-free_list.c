#include "lists.h"

/**
 * free_list - Frees a linked list and its strings
 * @head: Pointer to the head of the linked list
 *
 * Description:
 * This function frees each node in a linked list, including the
 * strings within each node. It iterates through the list and
 * frees the memory allocated for each node and its associated string.
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str); /* Free duplicated string */
		free(temp); /* free node */
	}
}

