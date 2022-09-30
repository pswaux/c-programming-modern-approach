/**
 *
 * Modify the broker.c program of Section 5.2 by making
 * both of the following changes:
 *
 *    (a) Ask the user to enter the number of shares and the price
 *        per share, instead of the value of the trade
 *
 *    (b) Add statements that compute the commission charged 
 *        by a rival broker ($33 plus 3¢ per share for fewer than 2000 shares;
 *        $33 plus 2¢ per share for 2000 shares or more). Display the rival's 
 *        commission as well as the commission charged by the original broker.
 *
 */

#include <stdio.h>

int main(void)
{
   int number_of_shares;
   float commission, rival_commission, price_per_share, value;

	printf("Enter the number of shares: ");
	scanf("%d", &number_of_shares);

   printf("Enter the price per share: ");
   scanf("%f", &price_per_share);

   value = number_of_shares * price_per_share;

	if (value < 2500.00f)
		commission = 30.00f + .017f * value;
	else if (value < 6250.00f)
		commission = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		commission = 76.00f + .0034f * value;
	else if (value < 50000.00f)
		commission = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		commission = 155.00f + .0011f * value;
	else
		commission = 255.00f + .0009f * value;

	if (commission < 39.00f)
		commission = 39.00f;

   /* rival's commission   */
   if (number_of_shares < 2000)
      rival_commission = 33.00f + (number_of_shares * .03f);
   else
      rival_commission = 33.00f + (number_of_shares * .02f);

	printf("Broker's commission: $%.2f\n", commission);
   printf("Rival's commission. $%.2f\n", rival_commission);

	return 0;
}
