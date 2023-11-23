#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the unsigned long integer
 * @index: the index of the bit to set, starting from 0
 *
 * Description:
 *    This function sets the value of a bit at a specified index to 1
 *    in the unsigned long integer pointed to by n. It uses bitwise OR
 *    with a mask created by shifting 1 to the left by the index.
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	/* Check if the pointer is NULL */
	if (n == NULL)
	{
		return (-1); /* Error: NULL pointer */
	}

	/* Check if the index is valid */
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	/* Set the bit at the specified index to 1 using bitwise OR */
	*n |= (1 << index);

	return (1);
}

