#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the product of two integers
 * @argc: CLI argument count
 * @argv: CLI argument vector - args passed
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1); /* CLI args is not equal to 3 */
	}

	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));

	return (0);
}
