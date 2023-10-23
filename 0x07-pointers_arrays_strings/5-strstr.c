#include "main.h"

/**
 * _strstr - locate a substring
 * @haystack: string
 * @needle: substring
 *
 * Description: The strstr() function finds the first occurrence of the
 * substring @needle in the string @haystack. The terminating null bytes('\\0')
 * are not compared.
 *
 * Return: return a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*n && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return (haystack); /* found substring */
		}

		haystack++;
	}

	return (NULL); /* substring not found */
}
