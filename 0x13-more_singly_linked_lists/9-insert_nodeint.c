#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to a pointer to the head of the linked list.
 * @idx: The index at which the new node should be inserted.
 * @n: The data to be stored in the new node.
 *
 * Description:
 * This function inserts a new node with the specified data at the given
 * position in a linked list. If the index is 0, the new node becomes the
 * new head of the list. If the index is greater than the length of the list,
 * the new node is added at the end.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - Address of the new node.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newNode, *current;
	unsigned int i, Nth = idx - 1;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = n;
	newNode->next = NULL;

	/* Special case: Insert at the beginning */
	if (idx  == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	/* Traverse the list to find the node before the desired index */
	current = *head;
	for (i = 0; i < Nth && current != NULL; i++)
	{
		current = current->next;
	}

	 /* Insert the new node into the list */
	newNode->next = current->next;
	current->next = newNode;
	return (newNode);
}
