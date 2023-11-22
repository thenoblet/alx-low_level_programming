#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Description:
 * This function takes a pointer to the head of a linked list and reverses the
 * order of its nodes. It uses the iterative approach with two pointers to
 * reverse the links between the nodes.
 *
 * Return:
 * A pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	/* Check if the list is empty */
	if (*head == NULL)
	{
		return (NULL);
	}

	/* Traverse the list and reverse the links */
	while (*head != NULL)
	{
		next = (*head)->next; /* Save the next node for traversal */
		(*head)->next = prev; /* Reverse the link to the previous node */
		prev = *head;  /* Move to the next pair of nodes */
		*head = next;  /* Move to the next pair of nodes for traversal */
	}

	/* Update the head to point to the new first node of the reversed list */
	*head = prev;

	return (*head);
}
