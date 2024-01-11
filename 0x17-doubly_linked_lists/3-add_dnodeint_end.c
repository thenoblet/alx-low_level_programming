#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list.
 * @head: Pointer to the pointer of the head of the list.
 * @n: Value to be stored in the new node.
 *
 * Description:
 * This function adds a new node with the given value at the end of a
 * doubly linked list. If the list is empty, it creates the first node.
 *
 * Return: Address of the new node, or NULL if memory allocation fails.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *current;

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL); /* Return NULL if memory allocation fails */

	/* initialise new node */
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			current->next = new_node;
			new_node->prev = current;
			break;
		}
		current = current->next; /* Move to the next node in the list */
	}
	return (new_node);
}

