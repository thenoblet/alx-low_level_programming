#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a linked list.
 * @head: A pointer to the head of the linked list.
 * @index: The index of the node to retrieve, starting at 0.
 *
 * This function returns a pointer to the node at the specified index in
 * the linked list. If the node does not exist, it returns NULL.
 *
 * Return: A pointer to the nth node, or NULL if the node does not exist.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current = head;

	/* Traverse the linked list until the specified index or the end is reached */
	for (i = 0; current != NULL; ++i)
	{
		if (i == index)
		{
			return (current); /* Return a pointer to the nth node */
		}

		current = current->next;
	}
	return (NULL); /* Return NULL if the node does not exist */
}
