#include "main.h"

/**
 * string_nconcat - concatenate two strings
 *
 * @s1: string 1
 * @s2: string 2
 * @n: number of characters to write from string @s2 to
 * the new string
 *
 * Return: A pointer to the concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *newString;
	size_t s2_len, total_len;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
	{
		s2 = "";
	}

	/* Calc. length of s2 or limit it to 'n' chars */
	s2_len = strlen(s2);
	if (n < s2_len)
		s2_len = n;

	total_len = strlen(s1) + s2_len;
	newString = malloc(sizeof(char) * (total_len + 1));
	if (newString == NULL)
	{
		return (NULL);
	}

	i = 0, j = 0;
	while (i < strlen(s1))
	{
		newString[i] = s1[i];
		++i;
	}

	while (j < n)
	{
		newString[i + j] = s2[j];
		++j;
	}

	return (newString);
}
