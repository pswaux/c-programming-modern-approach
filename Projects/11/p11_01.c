/**
 *
 * Modify Programming Project 7 from Chapter 2 so that it includes the following function:
 *
 *    void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);
 *
 * The function determines the smallest number of $20, $10, $5, and $1 bills necessary
 * to pay the amount represented by the dollars parameter. The twenties parameter points
 * to a variable in which the function will store the number of S20 bills required.
 * The tens, fives, and ones parameters are similar.
 *
 */
#include <stdio.h>

void pay_amount(int dollars, int *, int *, int *, int *);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   int dollars, twenties, tens, fives, ones;

   printf("Enter a dollar amount: ");
   scanf("%d", &dollars);

   pay_amount(dollars, &twenties, &tens, &fives, &ones);

   printf("$20 bills: %d\n", twenties);
   printf("$10 bills: %d\n", tens);
   printf(" $5 bills: %d\n", fives);
   printf(" $1 bills: %d\n", ones);

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
   *twenties = dollars / 20;
   dollars %= 20;

   *tens = dollars / 10;
   dollars %= 10;

   *fives = dollars / 5;
   dollars %= 5;

   *ones = dollars;
}
