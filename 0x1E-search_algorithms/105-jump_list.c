#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list of integers
 * using jump search.
 * @head: A pointer to the head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 * Otherwise, a pointer to the first node where the value is located.
 *
 */
listint_t *jump_list(listint_t *head, size_t size, int value)
{
	size_t jump_step, step_size;
	listint_t *current, *jump_node;

	if (head == NULL || size == 0)
	{
		return (NULL);
	}

	jump_step = 0;

	/* Determine the jump step size */
	step_size = sqrt(size);
	for (current = jump_node = head; jump_node->index + 1 < size &&
			jump_node->n < value;)
	{
		current = jump_node;
		for (jump_step += step_size; jump_node->index < jump_step;
				jump_node = jump_node->next)
		{
			/* Handle reaching the end of the list */
			if (jump_node->index + 1 == size)
			{
				break;
			}
		}
		printf("Value checked at index [%ld] = [%d]\n", jump_node->index,
				jump_node->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			current->index, jump_node->index);

	/* Linear search in the interval where the value is found */
	for (; current->index < jump_node->index && current->n < value;
			current = current->next)
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);

	/* Return node if value found, otherwise NULL */
	return (current->n == value ? current : NULL);
}
