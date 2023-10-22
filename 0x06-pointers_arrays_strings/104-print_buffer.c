#include "main.h"

/**
 * print_buffer - prints a buffer
 *
 * @b: buffer
 * @size: buffer size
 *
 * Return: void (nothing)
 */

void print_buffer(char *b, int size)
{
	int position, index;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (position = 0; position < size; position += 10)
	{
		printf("%08x: ", position);

		for (index = 0; index < 10; index++)
		{
			if ((index + position) >= size)
				printf("  ");
			else
				printf("%02x", *(b + index + position));

			if ((index % 2) != 0 && index != 0)
				printf(" ");
		}

		for (index = 0; index < 10; index++)
		{
			if ((index + position) >= size)
				break;
			else if (isprint(*(b + index + position)))
				printf("%c", *(b + index + position));
			else
				printf(".");
		}
		printf("\n");
	}
}
