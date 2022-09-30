/**
 *
 * Programming Project 8 in Chapter 2 asked you to write a program
 * that calculates the remaining balance on a loan after the first,
 * second, and third monthly payments. Modify the program so that it
 * also asks the user to enter the number of payments and then displays
 * the balance remaining after each of these payments.
 *
 */
#include <stdio.h>

int main(void)
{
   float amount = 0.0f;
	float interest_rate = 0.0f;
	float monthly_payment = 0.0f;
	float monthly_interest_rate = 0.0f;
   int number_of_payments = 0;

	printf("Enter amount of loan: ");
	scanf("%f", &amount);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

   printf("Enter number of payments: ");
   scanf("%d", &number_of_payments);

	interest_rate = interest_rate / 100;			// convert to percentage
	monthly_interest_rate = interest_rate / 12;	

   for (int i = 0; i < number_of_payments; i++) {
      amount = amount - monthly_payment + (amount * monthly_interest_rate);
	   printf("Balance remaining after #%d payment: $%.2f\n", i + 1, amount);
   }

	return 0;
}
