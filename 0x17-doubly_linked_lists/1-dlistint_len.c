#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a doubly linked list.
 * @h: Pointer to the head of the list.
 *
 * Description:
 * This function counts the number of nodes in a doubly linked list.
 *
 * Return: Number of nodes in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t node_count = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		node_count++; /* Increment the node count */
		h = h->next; /* Move to the next node */

	}

	return (node_count); /* Return the total number of nodes */
}
