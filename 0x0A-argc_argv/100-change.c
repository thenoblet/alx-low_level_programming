#include <stdio.h>
#include <stdlib.h>

/* coin values */
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define TWO_PENNIES 2
#define PENNY 1

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int calculate_twoPennies(int cents);
int countCoins(int cents);

/**
 * main - prints the minimum number of coins to make change
 *
 * @argc: CLI arg count
 * @argv: argument passed - cents
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int cents, coins;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (-1);
	}
	
	coins = countCoins(cents);
	printf("%d\n", coins);

	return (0);
}


int countCoins(int cents)
{
	int quarters, dimes, nickels, twoPennies, pennies;

	/* Calculate the number of quarters to give */
	quarters = calculate_quarters(cents);
	cents = cents - quarters * QUARTER;

	/* Calculate the number of dimes to give */
	dimes = calculate_dimes(cents);
	cents = cents - dimes * DIME;

	/* Calculate the number of nickels to give */
	nickels = calculate_nickels(cents);
	cents = cents - nickels * NICKEL;

	/* Calculate the number of pennies to give */
	pennies = calculate_pennies(cents);
	cents = cents - pennies * PENNY;

	/* Calculate the number of two pennies to give */
	twoPennies = calculate_twoPennies(cents);
	cents = cents - twoPennies * TWO_PENNIES;

	return (quarters + dimes + nickels + pennies + twoPennies);
}



int calculate_quarters(int cents)
{
	int quarters = 0;

	while (cents >= QUARTER)
	{
		cents -= QUARTER;
		quarters++;
	}
	return (quarters);
}

int calculate_dimes(int cents)
{
	int dimes = 0;

	while (cents >= DIME)
	{
		cents -= DIME;
		dimes++;
	}
	return (dimes);
}

int calculate_nickels(int cents)
{
	int nickels = 0;

	while (cents >= NICKEL)
	{
		cents -= NICKEL;
		nickels++;
	}
	return (nickels);
}

int calculate_twoPennies(int cents)
{
	int twoPennies = 0;

	while (cents >= TWO_PENNIES)
	{
		cents -= TWO_PENNIES;
		twoPennies++;
	}
	return (twoPennies);
}

int calculate_pennies(int cents)
{
	int pennies = 0;

	while (cents >= PENNY)
	{
		cents -= PENNY;
		pennies++;
	}
	return (pennies);
}
