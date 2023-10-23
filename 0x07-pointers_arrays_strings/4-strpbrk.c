#include "main.h"

/**
 * _strpbrk - searches for the first occurance of
 * of a char in @s
 *
 * @s: string
 * @accept: substring
 *
 * Description: The _strpbrk() function locates the first occurrence in the
 * string @s of any of the bytes in the string @accept.
 *
 * Return: A pointer to the byte in @s that matches one of the bytes in
 *  @accept, or NULL if no such byte is found.
 */

char *_strpbrk(char *s, char *accept)
{

	while (*s != '\0')
	{
		char *c = accept;

		while (*c != '\0')
		{
			if (*s == *c)
			{
				return (s);
			}
			c++;
		}
		s++; /* Move to the next character in s */
	}

	return (NULL);
}
