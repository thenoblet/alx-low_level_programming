#include "lists.h"
/**
 * free_listint - Frees a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * This function frees the memory occupied by each node in the linked list.
 * It starts from the head of the list, iterates through each node, and
 * frees the memory associated with it.
 */

void free_listint(listint_t *head)
{
	listint_t *next;
	listint_t *ptr = head;

	/* Traverse the linked list */
	while (ptr != NULL)
	{
		next = ptr->next; /* Save the next node before freeing the current node */
		free(ptr); /* Free the memory occupied by the current node */
		ptr = next;  /* Move to the next node */
	}
}

