/**
 *
 * Write a progrum that accepts a date from the user 
 * in the form mm/dd/yyyy and then displays it in the
 * form yyyymmdd:
 *		
 *		Enter a date (mm/dd/yyyy): 2/17/2011
 *		You entered the date 20110217
 *
 */

#include <stdio.h>

int main(void)
{
	int day = 0;
	int month = 0;
	int year = 0;

	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("You entered the date %d%02d%02d\n", year, month, day);
	return 0;
}
