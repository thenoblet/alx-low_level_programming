#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a linked list.
 *
 * @head: A pointer to a pointer to the head of the linked list.
 * @n: The value to be stored in the new node.
 *
 * This function creates a new node with the given value and adds it
 * at the end of the linked list. If the list is empty, the new node
 * becomes the head of the list.
 *
 * Return: A pointer to the newly created node.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{

	listint_t *newNode, *current;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = n;
	newNode->next = NULL;

	/* If the list is empty, new node becomes the head of the list */
	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	/* Traverse the linked list to find the last node.*/
	for (current = *head; current->next != NULL; current = current->next)
	{
		;
	}

	/* Set the next pointer of the last node to the new node */
	current->next = newNode;

	return (newNode);
}
