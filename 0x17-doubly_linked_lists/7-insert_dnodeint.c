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
	dlistint_t *current = *h, *new_node;

	if ((!*h && idx) || !h)
		return (0);

	while (idx > 1)
	{
		current = current->next;
		if (!current)
			return (0);
		idx--;
	}
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (0);
	if (!idx)
	{
		new_node->prev = NULL;
		if (current)
			current->prev = new_node;
		*h = new_node;
		new_node->next = current;
	}
	else
	{
		new_node->next = current->next;
		if (current->next)
			current->next->prev = new_node;
		current->next = new_node;
		new_node->prev = current;
	}
	new_node->n = n;
	return (new_node);
}
