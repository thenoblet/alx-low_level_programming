#include "main.h"


int is_lower(char c);
int is_upper(char c);
int is_separator(char c);

/**
 * cap_string - capitalises words
 *
 * @str: string to be capitalised
 *
 * Return: pointer to a string
 */


char *cap_string(char *str)
{
	int capitalise_next = 1;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_separator(str[i]))
		{
			capitalise_next = 1;
		}
		else if (capitalise_next && is_lower(str[i]))
		{
			str[i] = str[i] - 'a' + 'A';
			capitalise_next = 0;
		}
		else
		{
			capitalise_next = 0;
		}
	}

	return (str);

}

/**
 * is_lower - retursn lowercase char
 * @c: parameter
 * Return: lowercase
 */

int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}


/**
 * is_upper - checks for uppercase
 * @c: parameter
 * Return: uppercase
 */

int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}


/**
 * is_separator - checks for separators
 * @c: char to be checked
 * Return: if is separator, return 1, else return 0
 */

int is_separator(char c)
{
	char separators[] = " \t\n,;.!?\"(){}";
	int i;

	for (i = 0; separators[i]; i++)
	{
		if (c == separators[i])
		{
			return (1);
		}
	}

	return (0);
}
