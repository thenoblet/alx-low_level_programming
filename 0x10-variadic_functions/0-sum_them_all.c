#include "variadic_functions.h"

/**
 * sum_them_all - Calculate the sum of a variable number of arguments.
 * @n: The number of arguments.
 * @...: Variable number of arguments.
 *
 * Return: Sum of the variable arguments.
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int result = 0;
	va_list args;

	if (n == 0)
	{
		return (0);
	}

	/* Initialize the va_list to access the variable arguments */
	va_start(args, n);

	/* Loop through the variable arguments and calculate the sum */
	for (i = 0; i < n; ++i)
	{
		result += va_arg(args, int);
	}

	/* Clean up the variable arguments */
	va_end(args);

	return (result); /* Return the calculated sum */
}
