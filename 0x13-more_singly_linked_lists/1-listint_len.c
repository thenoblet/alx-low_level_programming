#include "lists.h"

/**
 * listint_len - Counts the number of nodes in a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * This function traverses a linked list starting from the given
 * head pointer and counts the number of nodes in the list.
 *
 * Return: The number of nodes in the linked list.
 */

size_t listint_len(const listint_t *h)
{
	const listint_t *head;
	size_t nodeCount = 0;

	/* Traverse the linked list */
	for (head = h; head != NULL; head = head->next)
	{
		nodeCount++; /* Increment the node count */
	}

	return (nodeCount);
}

