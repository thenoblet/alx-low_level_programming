#include "3-calc.h"

/**
 * main - Entry point for a simple calculator program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * This program takes two integer operands and an operator as command-line
 * arguments and performs the specified operation. It then prints the result.
 *
 * Return: 0 for success, exit status 98 or 99 for errors.
 */

int main(int argc, char *argv[])
{

	int a, b, result;
	char *operator;
	
	int (*operation)(int, int);

	/* Check the number of command line arguments */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* Parse first and third command line arguments as integers */
	a = atoi(argv[1]);
	operator = argv[2];
	b = atoi(argv[3]);

	 /* Get operation function based on the provided operator */
	operation = get_op_func(operator);

	/* Check if a valid operation function was obtained */
	if (operation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	/* Perform the operation and display the result */
	result = operation(a, b);
	printf("%d\n", result);

	return (0);
}
