#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: the unsigned long integer
 * @index: the index of the bit to retrieve, starting from 0
 *
 * Return: the value of the bit at index or -1 if an error occurred
 */

int get_bit(unsigned long int n, unsigned int index)
{
	/* Check if the index is valid */
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1); /* Error: Index out of bounds */
	}

	/* Shift the bit at the specified index to the rightmost position */
	/* Check if the bit at the index is 1 or 0 and return the result */
	return ((n & (1 << index)) ? 1 : 0);
}

