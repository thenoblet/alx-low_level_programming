#include "main.h"

/**
 * print_binary - prints a number in binary
 * @n: the integer
 *
 * Description:
 * This function recursively prints the binary representation of a given
 * unsigned long integer 'n'. It uses bitwise operations to extract each bit
 * and '_putchar' to print the result.
 *
 * Return: void
 */

void print_binary(unsigned long int n)
{

	if (n > 1)
	{
		/* Recursively call print_binary with n shifted right by 1 */
		print_binary(n >> 1);
	}

	/**
	 * Print the least significant bit by using bitwise AND
	 * with 1 and converting to ASCII
	 */
	_putchar((n & 1) + '0');
}

