#include "variadic_functions.h"

/**
 * print_all - prints anything based on the format provided
 *
 * @format: a list of types of arguments passed to the function
 */

void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	int num;
	float fnum;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				num = va_arg(args, int);
				printf("%d", num);
				break;
			case 'f':
				fnum = va_arg(args, double);
				printf("%f", fnum);
				break;
			case 's':
				str = va_arg(args, char *);
				if (!str)
					str = "(nil)"; /* "(nil)" if it's NULL */
				printf("%s", str);
				break;
			default:
				++i;
				continue;
		}

		if (format[i + 1])
			printf(", ");
		++i;
	}
	putchar('\n');
	va_end(args);
}
