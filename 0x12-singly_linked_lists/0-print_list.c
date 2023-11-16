#include "lists.h"


/**
 * print_list - Print the elements of a linked list
 * @h: Pointer to the head of the linked list
 *
 * Description:
 * This function traverses a linked list and prints the elements
 * of the list.
 * For each node, it prints the length of the string and
 * the string itself.
 * If the string is NULL, it prints "[0] (nil)".
 *
 * Return: Number of nodes in the linked list
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	list_t *head = (list_t *)h;

	if (head == NULL)
	{
		return (0); /* Return 0 for empty list */
	}

	while (head != NULL)
	{
		if (head->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			head->len = _strlen(head->str);
			printf("[%u] %s\n", head->len, head->str);
		}
		count++;
		head = head->next;
	}

	return (count);
}


/**
 * _strlen - Calculate the length of a string
 *
 * @s: The input string
 * Return: Length of the string
 */

size_t _strlen(const char *s)
{
	size_t len = 0;
	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}
