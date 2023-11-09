#include "variadic_functions.h"

/**
 * print_numbers - Print a variable number of integers.
 *
 * @separator: The string to be printed between numbers.
 * @n: The number of integers to be printed.
 * @...: Variable number of integers to be printed.
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	/* Initialize the va_list to access the variable arguments */
	va_start(args, n);

	if (n > 0)
	{
		 /* Loop through the variable arguments and print integers with separator */
		for (i = 0; i < n; ++i)
		{
			printf("%d", va_arg(args, int));
			if (separator != NULL && i < n - 1)
			{
				printf("%s", separator);
			}
		}
	}
	putchar('\n');
	va_end(args);
}
