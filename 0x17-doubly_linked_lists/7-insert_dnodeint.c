#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * in a doubly linked list.
 * @h: Pointer to the pointer of the head of the list.
 * @idx: Index at which the new node should be inserted.
 * @n: Value to be stored in the new node.
 *
 * Description:
 * This function inserts a new node with the given value at the specified index
 * in a doubly linked list. If the index is out of bounds, the function
 * returns NULL.
 *
 * Return: Address of the new node, or NULL if the insertion is not possible.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	size_t node_count = 0;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*h == NULL)
	{
		/* If the list is empty, set the new node as the head */
		*h = new_node;
		return (new_node);
	}

	current = *h;
	while (current != NULL)
	{
		if (node_count == idx)
		{
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
			if (new_node->next != NULL)
				new_node->next->prev = new_node;
			return (new_node);
		}
		node_count++;
		current = current->next;
	}

	return (NULL);
}
