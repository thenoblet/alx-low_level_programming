#include "main.h"

int _strlen(char *s);

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
	size_t s2_len, s1_len, total_len;
	unsigned int i, j;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	/* Calc. length of s2 or limit it to 'n' chars */
	s2_len = _strlen(s2);
	s1_len = _strlen(s1);
	if (n >= s2_len)
		n = s2_len;

	total_len = s1_len + n;
	newString = malloc(sizeof(char) * (total_len + 1));
	if (newString == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < s1_len)
	{
		newString[i] = s1[i];
		++i;
	}

	j = 0;
	while (j < n)
	{
		newString[i + j] = s2[j];
		++j;
	}
	newString[i + j] = '\0';

	return (newString);
}


/**
 * _strlen - returns the length of a string
 *
 * @s: parameter
 *
 * Return: length of a string
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}
