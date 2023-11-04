#include "main.h"

/* helper functions */
char *multiply(char *firstNum, char *secondNum);
int _strlen(char *s);


/**
 * main - Entry point of the program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 98 for errors.
 */

int main(int argc, char *argv[])
{
	char *result, *firstNum, *secondNum;
	unsigned int i, j, n, m;
	int index;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	firstNum = argv[1];
	secondNum = argv[2];

	for (i = 0, n = _strlen(firstNum); i < n; ++i)
	{
		if (!isdigit(firstNum[i]))
		{
			printf("Error\n");
			exit(98); /* exit, first number contains non-digit chars */
		}
	}

	for (j = 0, m = _strlen(secondNum); j < m; ++j)
	{
		if (!isdigit(secondNum[j]))
		{
			printf("Error\n");
			exit(98); /* exit, first number contains non-digit chars */
		}
	}
	result = multiply(firstNum, secondNum);
	/* resultLen = _strlen(result); */

	/* Find the position of the first non-zero digit */
	index = 0;
	while (result[index] == '0' && result[index + 1] != '\0')
	{
		index++;
	}

	/* Print the result from the first non-zero digit onwards */
	printf("%s\n", result + index);
	free(result);

	return (0);
}


/**
 * multiply - Multiply two positive numbers represented as strings.
 *
 * @firstNum: The first number.
 * @secondNum: The second number.
 *
 * Return: The result of multiplication.
 */

char *multiply(char *firstNum, char *secondNum)
{
	char *result;
	int i, j, l;
	int product, carry;

	int firstNumLen = _strlen(firstNum);
	int secondNumLen = _strlen(secondNum);
	int resultLen = firstNumLen + secondNumLen;

	result = malloc(sizeof(char) * (resultLen + 1));
	if (result == NULL)
	{
		exit(98); /* memory alloc failed*/
	}

	/* Initialize result array with '0's */
	for (i = 0; i < resultLen; ++i)
	{
		result[i] = '0';
	}
	result[resultLen] = '\0';

	for (j = firstNumLen - 1; j >= 0; --j)
	{
		carry = 0;
		for (l = secondNumLen - 1; l >= 0; --l)
		{
			/* Calc. product and update carry */
			product = ((firstNum[j] - '0') * (secondNum[l] - '0') +
					(result[j + l + 1] - '0') + carry);
			carry = product / 10;
			result[j + l + 1] = ((product % 10) + '0'); /* Update the result */
		}
		result[j] += carry; /*  Update result with final carry */
	}
	return (result);
}


/**
 * _strlen - returns the length of a string
 *
 * @s: parameter
 *
 * Return: length of a string
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}
