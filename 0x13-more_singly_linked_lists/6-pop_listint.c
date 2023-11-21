#include "lists.h"

/**
 * pop_listint - Deletes the head node of a linked list and returns its data.
 * @head: A pointer to a pointer to the head of the linked list.
 *
 * Description: This function removes the head node from the linked list,
 * frees the memory occupied by it, and returns the data stored in
 * the original head.
 *
 * Return: The data (n) of the removed head node, or 0 if the list is empty.
 */

int pop_listint(listint_t **head)
{
	int data = 0;
	listint_t *newNode;

	/* Check if the list is empty */
	if (head == NULL || *head == NULL)
	{
		return (0);
	}

	newNode = *head; /* Save the address of the current head node */
	data = newNode->n; /* Retrieve the data from the head node */
	*head = newNode->next; /* Update the head pointer to the next node */

	free(newNode);

	return (data);
}
