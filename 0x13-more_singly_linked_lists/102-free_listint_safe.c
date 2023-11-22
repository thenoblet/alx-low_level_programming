#include "lists.h"

/**
 * free_listint_safe - Safely frees a linked list of integers
 * @head: Pointer to the head of the linked list
 *
 * Description:
 * This function safely frees a linked list of integers and returns
 * the number of nodes in the list. It avoids potential issues with
 * freeing nodes in a regular loop by checking for NULL pointers
 * and comparing the addresses of nodes.
 *
 * Return: the number of nodes in the free'd list
 */

size_t free_listint_safe(listint_t **head)
{
	size_t count = 0;
	listint_t *current = *head;

	 /* Check if the head pointer or the list itself is NULL */
	if (*head == NULL || head == NULL)
	{
		return (0);
	}

	while (1)
	{
		current = (*head)->next;
		free(*head);
		count++;

		if (current == NULL || *head <= current)
		{
			*head = 0;
			return (count);
		}
		*head = current;
	}

}
