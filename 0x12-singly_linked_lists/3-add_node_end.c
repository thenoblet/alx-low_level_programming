#include "lists.h"

/**
 * add_node_end - Add a new node at the end of a linked list
 * @head: Pointer to the pointer of the head of the list
 * @str: String to be duplicated and added to the new node
 *
 * Return: Address of the new element, or NULL if it fails
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *current;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* Duplicate the string */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node); /* dup. failed, free memory */
		return (NULL);
	}

	/* If the list is initially empty, update the head pointer */
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		return (new_node); /* Return address of the new element */
	}

	 /* Traverse the list to find the last node */
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}

	/* Add the new node at the end of the list */
	current->next = new_node;
	new_node = NULL;

	return (new_node);
}


