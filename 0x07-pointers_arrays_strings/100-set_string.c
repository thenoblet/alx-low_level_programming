#include "main.h"

/**
 * set_string - sets the value of a pointer to char
 *
 * @s: pointer to char pointer (string)
 * @to: string to set @s to
 *
 * Return: Void (nothing)
 */

void set_string(char **s, char *to)
{
	*s = to;
}
