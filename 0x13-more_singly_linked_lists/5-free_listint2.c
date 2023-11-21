#include "lists.h"

/**
 * free_listint2 - Frees a linked list and sets the head to NULL.
 *
 * @head: A pointer to a pointer to the head of the linked list.
 *
 * This function frees the memory occupied by each node in the linked list.
 * It also sets the head pointer to NULL after freeing all nodes.
 *
 */

void free_listint2(listint_t **head)
{
	listint_t *next;
	listint_t *ptr;

	/* Return if the head pointer is already NULL or the list is empty */
	if (head == NULL || *head == NULL)
	{
		return;
	}

	/* Traverse the linked list */
	ptr = *head;
	while (ptr != NULL)
	{
		next = ptr->next; /* Save the next node before freeing the current node */
		free(ptr); /* Free the memory occupied by the current node */
		ptr = next;  /* Move to the next node */
	}

	*head = NULL; /* Set head pointer to NULL after freeing all nodes */
}

