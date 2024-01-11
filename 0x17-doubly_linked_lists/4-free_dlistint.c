#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the list.
 *
 * Description:
 * This function frees each node in a doubly linked list and
 * sets the head to NULL.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	if (head == NULL)
		return; /* Return if the list is already empty */

	while (head != NULL)
	{
		current = head; /* Save the current node */
		free(current); /* Free the memory of the current node */

		/* Set the current node to NULL to avoid dangling pointers */
		current = NULL;
		head = head->next; /* Move to the next node */
	}
}
