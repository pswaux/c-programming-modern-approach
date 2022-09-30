/**
 *
 * In one state, single residents are subject to the following income tax:
 * 
 *    Income            Amount of tax
 *    Not over $750     1% of income
 *    $750 - $2.250     $7.50    plus 2% of amount over $750
 *    $2.250 - $3.750   $37.50   plus 3% of amount over $2.250
 *    $3.750 - $5.250   $82.50   plus 4% of amount over $3.750
 *    $5.250 - $7.000   $142.50  plus 5% of amount over $5.250
 *    Over $7.000       $230.00  plus 6% of amount over $7.000
 * 
 * Write a program that asks the user to enter the amount of 
 * taxable income, the displays the tax due 
 *
 */

#include <stdio.h>

int main(void) 
{
   float income, tax;

   printf("Enter the amount of income: ");
   scanf("%f", &income);

   if (income <= 750.00f)
      tax = income * .01f;
   else if (income <= 2250.00f)
      tax = 7.50f + ((income - 750.00f) * .02f);
   else if (income <= 3750.00f)
      tax = 37.50f + ((income - 2250.00f) * .03f);
   else if (income <= 5250.00f)
      tax = 82.50f + ((income - 3750.00f) * .04f);
   else if (income <= 7000.00f)
      tax = 142.50f + ((income - 5250.00f) * .05f);
   else
      tax = 230.00f + ((income - 7000.00f) * .06f);

   printf("The tax is: %.2f\n", tax);
   return 0;
}
