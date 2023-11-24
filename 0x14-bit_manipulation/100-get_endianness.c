#include "main.h"

/**
 * get_endianness - checks the endianness of the system
 *
 * Description:
 *    This function checks whether the system is big endian or little endian.
 *    It does so by creating a pointer to a 32-bit integer and then
 *    checking the value of the first byte to determine the endianness.
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	/* Create a 32-bit integer with a known value (1) */
	uint32_t value = 1;

	/**
	 * Create a pointer to an 8-bit integer and point
	 * it to the address of the 32-bit integer
	 */
	uint8_t *byte = (uint8_t *)&value;

	/* Check the value of the first byte */
	return (*byte == 1);
}
