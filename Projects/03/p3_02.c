/**
 *
 * Write a program that formats product information entered by the user. 
 * A session with the program should look like this:
 *
 *	Enter item number: 583
 *	Enter unit price: 13.5
 *	Enter purchase date (mm/dd/yyyy): 10/24/2010
 *
 *	Item		Unit			Purchase
 *			   Price			Date
 *	583		$ 13.50		10/24/2010
 *
 * The item number and date should be left justified; the unit price
 * should be right justified. Allow dollar amounts up to $9999.90. 
 * Hint: Use tabs to line up the columns.
 *
 */

#include <stdio.h>

int main(void) 
{
	int item_number = 0;
	float unit_price = 0.0f;
	int day, month, year;

	printf("Enter item number: ");
	scanf("%d", &item_number);

	printf("Enter unit price: ");
	scanf("%f", &unit_price);

	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

	/* heading	*/
	printf("Item\t\tUnit\t\tPurchase\n    \t\tPrice\t\tDate\n");
	printf("%-16d$%7.2f%10.02d/%02d/%d\n", item_number, unit_price,
			month, day, year);

	return 0;
}
