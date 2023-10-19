#include "main.h"

/**
 * string_toupper - changes string to uppercase
 *
 * @str: string to be converted
 *
 * Return: Pointer to the string with uppercase chars
 */


char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			/* convert lowercase to uppercase */
			str[i] -= 32;
		}
		i++;
	}

	return (str);
}
