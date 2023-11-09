#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for a program that prints opcodes
 * of its own main function.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Description: This program checks the number of command-line arguments,
 * converts an argument to an integer, and then prints the opcodes
 * of its own `main` function.
 * It validates the input and prints error messages if necessary.
 *
 * Return: 0 for success, exit status 1 or 2 for errors.
 */

int main(int argc, char *argv[])
{
	unsigned char *bytes;
	int i, num_bytes;

	/* Check if the correct number of command-line arguments is provided */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* convert the argument to an integer and check if it's negative */
	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/* ast the address of the main function to an array of bytes */
	bytes = (unsigned char *)main;

	/* Iterate through the bytes and print their hexadecimal representation */
	for (i = 0; i < num_bytes; ++i)
	{
		printf("%02x", bytes[i]);
		if (i == num_bytes - 1)
			printf("\n");
		else
			printf(" ");
	}
	return (0);
}
