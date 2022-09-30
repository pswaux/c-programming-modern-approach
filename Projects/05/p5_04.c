/**
 *
 * Here's a simplified version of the Beaufort scale 
 * which is used to estimate wind force:
 * 
 *    Speed (knots)    Description
 *    Less than 1      Calm
 *    1-3              Light air
 *    4-27             Breeze
 *    28-47            Gale
 * 	48-63            Storm
 * 	Above 63         Hurricane
 * 
 * Write a program that asks the user to enter a wind speed (in knots),
 * then displays the corresponding description.
 *
 */

#include <stdio.h>

int main(void) 
{
	int wind = 0;

	printf("Please enter a wind speed (in knots): ");
	scanf("%d", &wind);

	if (wind < 1)
		printf("Calm\n");
	else if (wind < 4)
		printf("Light air\n");
	else if (wind < 28)
		printf("Breeze\n");
	else if (wind < 48)
		printf("Gale\n");
	else if (wind < 64)
		printf("Storm\n");
	else
		printf("Hurricane\n");

	return 0;
}
