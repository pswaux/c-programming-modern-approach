/**
 *
 * Extend the program in Programming Project 1 to handle three-digit numbers.
 *
 */

#include <stdio.h>

int main(void)
{
	int number = 0;
	int reversal = 0;

	printf("Enter a three-digit number: ");
	scanf("%d", &number);

	reversal = 100 * (number % 10);
	number /= 10;

	reversal += 10 * (number % 10);
	number /= 10;

	reversal += number;

	printf("The reversal is: %d\n", reversal);
	return 0;
}
