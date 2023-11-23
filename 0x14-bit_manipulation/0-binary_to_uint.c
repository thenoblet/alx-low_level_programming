#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if:
 * - there is one or more chars in the string b that is not 0 or 1
 * - b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	/* Check if the input string is NULL */
	if (b == NULL)
	{
		return (0);
	}


	for (i = 0; b[i] != '\0'; ++i)
	{
		/* Check if the character is not 0 or 1 */
		if (!is_binary(b[i]))
		{
			return (0); /* Invalid input, return 0 */
		}

		/* Convert character to integer and update result */
		result = ((result << 1) | (b[i] - '0'));
	}

	return (result);
}

