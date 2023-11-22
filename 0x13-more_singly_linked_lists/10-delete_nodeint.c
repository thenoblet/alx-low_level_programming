#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node at a specified index
 * in a linked list
 *
 * @head: pointer to a pointer to the head of the linked list
 * @index: index of the node to be deleted
 *
 * Description:
 * This function deletes a node at a specified index in a singly linked list.
 * It takes a pointer to a pointer to the head of the list and the index of the
 * node to be deleted. The function returns 1 if successful, indicating
 * the node has been deleted, and -1 if an error occurs (e.g., an empty list or
 * an index out of bounds).
 *
 * Return: 1 if successful, -1 if an error occurs
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i, Nth = index - 1;
	listint_t *current = *head, *toDelete;

	/* Check if the linked list is empty */
	if (*head == NULL)
	{
		return (-1);
	}

	/* If index is 0, delete the head */
	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	/* Traverse to the n-1th node */
	for (i = 0; i < Nth; i++)
	{
		/* Check if the linked list is shorter than the specified index */
		if (current == NULL || current->next == NULL)
		{
			return (-1);
		}
		current = current->next;
	}

	/* Remove the node at the specified index */
	toDelete = current->next; /* Store the node to be deleted */
	current->next = toDelete->next; /* skip the node to be deleted */
	free(toDelete);

	return (1);
}
