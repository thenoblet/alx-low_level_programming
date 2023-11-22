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

	for (; ; count++)
	{
		 /* Save the next node before freeing the current one */
		current = (*head)->next;
		free(*head);  /* Free the current node */

		/*
		 * check if the next node is NULL or if the address of the current
		 * head is less than or equal to the next node. If true, set head to
		 * NULL and return the count.
		 */
		if (current == NULL || *head <= current)
		{
			*head = 0;
			return (count);
		}

		*head = current; /* Move the head pointer to the next node */
	}
}
