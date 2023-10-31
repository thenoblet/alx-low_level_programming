#include "main.h"

/**
 * create_array - creates an array of chars
 *
 * @size: size of chars
 * @c: char to be intialised
 *
 * Return: Pointer to the array
 */

char *create_array(unsigned int size, char c)
{
	char *ch;
	unsigned int i;

	if (size == 0)
	{
		return (NULL); /* */
	}

	ch = (char *)malloc(size * sizeof(char));
	if (ch == NULL)
	{
		return (NULL); /* memory allocation not successfull */
	}

	/* Initialize the character array with the specified character */
	for (i = 0; i < size; ++i)
	{
		ch[i] = c;
	}

	return (ch); /* return ptr to the array */
}
