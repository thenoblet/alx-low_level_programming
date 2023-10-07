#include <stdio.h>

/**
 * main - prints all possible different combinations of three digits.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int firstDigit;
	int secondDigit;
	int thirdDigit;

	for (firstDigit = 0; firstDigit <= 7; firstDigit++)
	for (secondDigit = firstDigit + 1; secondDigit <= 8; secondDigit++)
	{
		for (thirdDigit = secondDigit + 1; thirdDigit <= 9; thirdDigit++)
		{
			putchar('0' + firstDigit);
			putchar('0' + secondDigit);
			putchar('0' + thirdDigit);

			if (firstDigit == 7 && secondDigit == 8 && thirdDigit == 9)
			{
				putchar('\n');
			}
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	return (0);
}

