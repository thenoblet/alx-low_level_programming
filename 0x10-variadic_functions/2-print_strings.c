#include "variadic_functions.h"

/**
 * print_strings - prints strings followed by a separator
 * @separator: the string to be printed between strings
 * @n: the number of strings passed to the function
 * @...: variable number of string arguments
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	/* Initialize the va_list to access the variable arguments */
	va_start(args, n);

	if (n > 0)
	{
		 /* Loop through the variable arguments and print string with separator */
		for (i = 0; i < n; ++i)
		{
			str = va_arg(args, char *);

			printf("%s%s",
					(str) ? str : "(nil)", /* print the string or (nil) if NULL */
					(separator && i < n - 1) ? separator : "");
		}
	}
	putchar('\n');
	va_end(args);
}
