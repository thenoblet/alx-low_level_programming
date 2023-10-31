#include "main.h"

/**
 * str_concat - concatenate strings
 *
 * @s1: base string
 * @s2: string to be concatenated
 *
 * Return: pointer to concatenated strings
 */

char *str_concat(char *s1, char *s2)
{
	char *str;
	size_t len_s1, len_s2;
	unsigned int i, j;

	/* Handle NULL strings as empty strings */
	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	/* Calculate the lengths of s1 and s2 */
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);

	/* Allocate memory for the concatenated string */
	str = (char *)malloc(len_s1 + len_s2 + 1); /* +1 for the null terminator */
	if (str == NULL)
		return (NULL);

	/* copy s1 and s2 into the destination string */
	for (i = 0; i < len_s1; ++i)
	{
		str[i] = s1[i];
	}

	for (j = 0; j < len_s2; j++)
	{
		str[len_s1 + j] = s2[j];
	}

	str[len_s1 + len_s2] = '\0'; /* add sentinel char to str */

	return (str);
}
