#include "main.h"

/* helper function prototypes */
int _ispalindrome(char *str, int start, int end);
int _strlen(char *str);


/**
 * is_palindrome - Checks if a string is a palindrome
 *
 * @s: The input string to check.
 *
 * Return: 1 if it's a palindrome, 0 if not.
 */

int is_palindrome(char *s)
{
	if (*s == '\0')
	{
		return (1); /* It's a palindrome (empty string). */
	}

	return (_ispalindrome(s, 0, _strlen(s) - 1));
}


/**
 * _ispalindrome - Recursive function to check if a string is a palindrome
 *
 * @str: input string to check.
 * @start: starting index.
 * @end: ending index.
 *
 * Return: 1 if it's a palindrome, 0 if not.
 */

int _ispalindrome(char *str, int start, int end)
{
	/* Check if chars at positions 'start' and 'end' are not equal */
	if (str[start] != str[end])
	{
		return (0); /* Not a palindrome */
	}

	/* Check if 'start' has crossed or is equal to 'end' (base case) */
	if (start >= end)
	{
		return (1); /* a palindrome */
	}

	/* Recursively call the function with updated 'start' and 'end' indices */
	return (_ispalindrome(str, start + 1, end - 1));
}


/**
 * _strlen - Calculates the length of a string.
 *
 * @str: input string to measure.
 *
 * Return: length of the string.
 */

int _strlen(char *str)
{
	if (*str == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + _strlen(str + 1));
	}
}
