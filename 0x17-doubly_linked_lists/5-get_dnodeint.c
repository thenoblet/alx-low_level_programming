#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a doubly linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to be retrieved.
 *
 * Description:
 * This function returns the node at the specified index in a
 * doubly linked list. The index starts at 0.
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t node_count = 0;

	if (head == NULL)
		return (NULL); /* Return NULL if the list is empty */

	while (head != NULL)
	{
		if (index == node_count)
		{
			/* Return the current node if the index matches */
			return (head);
		}
		node_count++; /* Increment the node count */
		head = head->next; /* Move to the next node */
	}

	return (NULL); /* If the index is not found, return NULL */
}
