/**
 *
 * Rewrite the program in Programming Project 2 so that it prints 
 * the reversal of a three-digit number without using arithmetic 
 * to split the number into digits. 
 * Hint: See the upc.c program of Section 4.1.
 *
 */

#include <stdio.h>

int main(void) 
{
	int first, middle, last;

	printf("Enter a three-digit number: ");
	scanf("%1d%1d%1d", &first, &middle, &last);

	printf("The reversal is: %d\n", (100 * last) + (10 * middle) + first);
	return 0;
}
