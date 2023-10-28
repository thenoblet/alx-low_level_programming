#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Prints the sum of positive integers
 *
 * @argc: CLI argument count
 * @argv: CLI arggument vector -- args passed.
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int sum = 0;
	int i;

	/* check for CLI arguments */
	if (argc == 1)
	{
		printf("%d\n", sum);
		return (0);
	}

	/* iterate over CLI args */
	for (i = 1; i < argc; i++)
	{
		char *arg = argv[i];

		/* Check if the argument contains non-digit symbols */
		while (*arg != '\0')
		{
			if (!isdigit(*arg))
			{
				printf("Error\n");
				return (1);
			}
			arg++;
		}
		/* Reset the arg pointer to the beginning of the argument string */
		arg = argv[i];

		/* Convert the argument to an integer and add it to the sum */
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum); /* print sum */

	return (0);
}
