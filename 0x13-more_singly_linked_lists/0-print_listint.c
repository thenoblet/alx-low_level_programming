#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Description: This function traverses a linked list starting from
 * the given head pointer and prints the value of each node.
 * It counts the number of nodes in the list and returns the total count.
 *
 * Return: The number of nodes in the linked list.
 */

size_t print_listint(const listint_t *h)
{
	const listint_t *head;
	size_t nodeCount = 0;

	/* Traverse the linked list */
	for (head = h; head != NULL; head = head->next)
	{
		printf("%d\n", head->n);
		nodeCount++;
	}

	return (nodeCount);
}
