#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a linked list.
 *
 * @head: A pointer to a pointer to the head of the linked list.
 * @n: The value to be stored in the new node.
 *
 * This function creates a new node with the given value and adds it
 * at the beginning of the linked list. The head pointer is updated
 * to point to the new node.
 *
 * Return: A pointer to the newly created node.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = n;
	newNode->next = NULL;

	if (*head != NULL)
	{
		newNode->next = *head;
	}
	/* Update the head pointer to point to the new node */
	*head = newNode;

	return (*head);
}
