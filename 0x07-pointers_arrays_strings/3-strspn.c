#include "main.h"

/**
 * _strspn - get length of a prefix substring
 * @s: string
 * @accept: substring
 *
 * Description: The _strspn() function calculates the length (in bytes) of the
 * initial segment of @s which consists of bytes in @accept.
 *
 * Return: The number of bytes in the initial segment of @s which
 * consist only of bytes from @accept.
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int counter = 0;

	while (*s != '\0')
	{
		/* Reset the pointer to the start of accept for each char in s */
		char *c = accept;

		/* bool flag to check if char is in accept */
		bool found = false;

		while (*c != '\0')
		{
			if (*s == *c)
			{
				found = true; /* char found */
				break; /* exit inner loop */
			}
			c++;
		}

		if (found)
		{
			counter++; /* increment counter if found */
		}
		else
		{
			break; /* Exit loop if char in s is not in accept */
		}

		s++; /* move to next char in s */
	}

	return (counter);
}
