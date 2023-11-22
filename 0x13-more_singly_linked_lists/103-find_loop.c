#include "lists.h"

/**
 * find_listint_loop - Finds the starting node of a loop in a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Description:
 * This function uses Floyd's cycle-finding algorithm to detect and find the
 * starting node of a loop in a linked list.
 *
 * Return: If no loop is found, returns NULL.
 * Otherwise, returns the starting node of the loop.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	/* Check if the linked list is empty or has only one element */
	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}

	/* Initialize pointers for cycle detection */
	slow = head->next;
	fast = (head->next)->next;

	/* Detect loop using Floyd's cycle-finding algorithm */
	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
		{
			/* Reset slow to the head and move both pointers until they meet */
			slow = head;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			/* Return the starting node of the loop */
			return (slow);
		}

		/* Move pointers */
		slow = slow->next;
		fast = (fast->next)->next;

	}
	return (NULL); /* No loop found, return NULL */

}

