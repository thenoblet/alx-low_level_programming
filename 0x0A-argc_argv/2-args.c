#include <stdio.h>

/**
 * main - Prints CLI arguments, including the program name
 *
 * @argc: CLI argument count
 * @argv: CLI argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i = 0;

	while (i < argc)
	{
		puts(argv[i++]); /* printf("%s\n", argv[i++]); -- works too */
	}

	return (0);
}
