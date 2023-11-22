#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: Pointer to the head of the list
 *
 * Description:
 * This function prints the nodes of a linked list, handling a case where a
 * loop is detected in the list. It uses a for loop to traverse the list,
 * printing each node's information. If a loop is detected, it prints the node
 * after the loop and breaks out of the loop early. The total count of nodes
 * is returned.
 *
 * Return:  The number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodeCount = 0;
	const listint_t *current = head;

	 /* Return 0 if the list is empty */
	if (head == NULL)
	{
		return (0);
	}

	 /* Traverse the list */
	for (; current != NULL; current = current->next)
	{
		/* Print node information */
		printf("[%p] %d\n", (void *)current, current->n);
		nodeCount++;

		/* Check for a loop in the linked list */
		if (current->next >= current || current->next == NULL)
		{
			break;
		}
	}

	if (current->next)
	{
		printf("-> [%p] %d\n", (void *)current->next, current->next->n);
	}

	return (nodeCount);
}
