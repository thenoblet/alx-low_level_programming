#include "main.h"


/**
 * wildcmp - compares two strings.
 *
 * @s1: 1st string
 * @s2: 2nd string - may contain '*' as a special character.
 *
 * Return: 1 if are identical, 0 if not.
 */


int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
	{
		return (0); /* No match if '*' at the end of s2 and s1 is empty. */
	}

	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1); /*match if we get to the end both strings. */
	}

	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1)); /* Continue checking if chars match. */
	}

	if (*s2 == '*')
	{
		/* Check with '*' as a wildcard. */
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	}

	return (0); /* No match found, chars don't match. */
}
