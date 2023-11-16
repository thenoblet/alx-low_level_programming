#include "lists.h"


/**
 * list_len - Get the number of elements in a linked list
 * @h: Pointer to the head of the linked list
 *
 * Description:
 * This function calculates and returns the number of elements (nodes) in a
 * linked list. It iterates through the list starting from the provided head,
 * incrementing a counter for each node, and returns the total count.
 *
 * Return: Number of elements in the linked list
 */

size_t list_len(const list_t *h)
{
	size_t count = 0;

	/* Cast the provided head to list_t pointer */
	list_t *head = (list_t *)h;

	if (head == NULL)
	{
		return (0); /* Return 0 for empty list */
	}

	/* Iterate through the linked list */
	while (head != NULL)
	{
		count++;
		head = head->next; /* Move to the next node */
	}

	return (count);
}
