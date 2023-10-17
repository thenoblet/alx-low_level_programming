#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
* main - Entry point.
*
* Return: Always 0.
*/

int main(void)
{
	int password_sum = 0, random_char, i = 0;
	char password[10000], *result = password;

	srand(time(NULL));

	while (password_sum < 2772)
	{
		random_char = rand() % 96 + 32;

		if (2772 - password_sum > 126)
		{
			password[i] = random_char;
			password_sum += random_char;
		}
		else if (2772 - password_sum < 32)
		{
			i = 0;
			password_sum = 0;
		}
		else
		{
			password[i] = 2772 - password_sum;
			password_sum = 2772;
		}
		i++;
	}
	printf("%s", result);

	return (0);
}
