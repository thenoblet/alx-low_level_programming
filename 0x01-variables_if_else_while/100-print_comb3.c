#include <stdio.h>

/**
 * main - prints all possible different combinations of two digits.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int firstdigit;
	int seconddigit;

	for (firstdigit = 0; firstdigit <= 8; firstdigit++)
	{
		for (seconddigit = firstdigit + 1; seconddigit <= 9; seconddigit++)
		{
			putchar('0' + firstdigit);
			putchar('0' + seconddigit);

			if (firstdigit == 8 && seconddigit == 9)
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
