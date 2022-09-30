/**
 *
 * Write a program that prompts the user to enter a telephone number
 * in the form (xxx) xxx-xxxx and then displays the number in the form
 * xxx.xxx.xxxx:
 *
 *    Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
 *    You entered 404.817.6900
 *
 */

#include <stdio.h>

int main(void)
{
	int prefix, area, number;

	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf("(%d) %d-%d", &prefix, &area, &number);

	printf("You entered %d.%d.%d\n", prefix, area, number);

	return 0;
}
