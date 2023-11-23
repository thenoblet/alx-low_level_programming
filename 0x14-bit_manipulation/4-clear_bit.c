#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the unsigned long integer
 * @index: the index of the bit to clear, starting from 0
 *
 * Description:
 *    This function sets the value of a bit at a specified index to 0
 *    in the unsigned long integer pointed to by n. It uses bitwise AND
 *    with the complement of a mask created by shifting 1 to the left
 *    by the index.
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	/* Check if the pointer is NULL */
	if (n == NULL)
	{
		return (-1);
	}

	/* Check if the index is valid */
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1); /* Error: Index out of bounds */
	}

	/**
	 * Clear the bit at the specified index to 0 using bitwise AND
	 * with the complement of the mask
	 */
	*n &= ~(1 << index);

	return (1);
}
