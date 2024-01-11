#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list.
 * @head: Pointer to the pointer of the head of the list.
 * @n: Value to be stored in the new node.
 *
 * Description:
 * This function adds a new node with the given value at the beginning of a
 * doubly linked list. If the list is empty, it creates the first node.
 *
 * Return: Address of the new node, or NULL if memory allocation fails.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	/* initialise new node */
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* handle insertion when the list is empty */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* handle insertion for non-empty list */
	(*head)->prev = new_node;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

