#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted singly linked list of
 * integers using linear skip.
 * @list: A pointer to the head of the linked list to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 * Otherwise, a pointer to the first node where the value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *next_jump;

	if (list == NULL)
	{
		return (NULL);
	}

	for (current = next_jump = list; next_jump->next != NULL &&
			next_jump->n < value;)
	{
		current = next_jump;

		if (next_jump->express != NULL)
		{
			next_jump = next_jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
					next_jump->index, next_jump->n);
		}
		else
		{
			while (next_jump->next != NULL)
				next_jump = next_jump->next;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			current->index, next_jump->index);


	for (; current->index < next_jump->index && current->n < value;
			current = current->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	}
	printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);

	/* Return node if value found, otherwise NULL */
	return (current->n == value ? current : NULL);
}
