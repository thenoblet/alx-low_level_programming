#include <stdio.h>

/**
 * main - Prints the number of arguments passed into program
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, __attribute__((unused)) char *argv[])
{
	/* print no of CLI arguments */
	printf("%d\n", argc - 1);

	return (0);
}
