#include <stdio.h>

/**
 * main - Prints the name of the program
 * 
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
	/* could use "(void) argc;" to indicate unused parameter */

	printf("%s\n", argv[0]);

	return (0);
}
