#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position in a doubly linked list.
 * @head: Pointer to the pointer of the head of the list.
 * @index: Index of the node to be deleted.
 *
 * Description:
 * This function deletes the node at the specified index in a doubly linked list.
 * If the index is out of bounds, it returns -1. Otherwise, it returns 1 upon successful deletion.
 *
 * Return: 1 if successful, -1 if the index is out of bounds or deletion fails.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head, *temp;

	if (!head || !*head)
		return (-1);

	if (!index)
	{
		*head = current->next;
		if (current->next)
			current->next->prev = NULL;
		free(current);
		return (1);
	}
	while (index > 1)
	{
		current = current->next;
		if (!current)
			return (-1);
		index--;
	}
	temp = current->next;
	if (!temp)
		return (-1);
	current->next = temp->next;
	if (temp->next)
		temp->next->prev = current;
	free(temp);
	return (1);
}
