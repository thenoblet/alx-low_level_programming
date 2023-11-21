#include "lists.h"

/**
 * sum_listint - calculates the sum of the values in a linked list.
 *
 * @head: A pointer to the head of the linked list.
 *
 * Return: The sum of the values in the linked list.
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current;

	 /* Check if the linked list is empty. */
	if (head == NULL)
	{
		return (0);
	}

	/* traverse linked list */
	for (current = head; current != NULL; current = current->next)
	{
		sum += current->n; /* Add the value of the current node to sum. */
	}

	return (sum);
}
