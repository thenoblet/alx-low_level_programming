#include "main.h"

/**
 * flip_bits - returns the number of bits to flip to get from n to m
 * @n: the first unsigned long integer
 * @m: the second unsigned long integer
 *
 * Description:
 *    This function calculates the number of bits that need to be flipped
 *    in order to transform the unsigned long integers n and m into each other.
 *    It uses bitwise XOR to find the differing bits and counts the set bits
 *    using Brian Kernighan's algorithm without using % or / operators.
 *
 * Return: The number of bits to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int bit_count = 0;

	/* Count the set bits using Brian Kernighan's algorithm */
	while (xor_result)
	{
		 /* Clear the rightmost set bit and increment the counter */
		xor_result &= (xor_result - 1);
		++bit_count;
	}

	/* Return the total count of set bits */
	return (bit_count);
}
