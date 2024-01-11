#include "lists.h"

/**
 * sum_dlistint - Computes the sum of all the data (n) in a doubly linked list.
 * @head: Pointer to the head of the list.
 *
 * Description:
 * This function traverses a doubly linked list and calculates the sum of all
 * the data (n) values in the nodes.
 *
 * Return: Sum of the data values, or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int data_sum = 0;

	if (head == NULL)
		return (0); /* Return 0 if the list is empty */

	while (head != NULL)
	{
		/* Add the value of the current node to the sum */
		data_sum += head->n;
		head = head->next; /* Move to the next node */
	}

	return (data_sum); /* Return the sum of the data values */
}
