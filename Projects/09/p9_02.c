/**
 *
 * Modify Programming Project 5 from Chapter 5 so that it
 * uses a function to compute the amount of income tax.
 * When passed an amount of taxable income, the function
 * will return the tax due.
 *
 */
#include <stdio.h>

/* function prototypes  */
float compute_tax(float);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   float income, tax;

   printf("Enter the amount of income: ");
   scanf("%f", &income);

   tax = compute_tax(income);

   printf("The tax is: %.2f\n", tax);
   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

float compute_tax(float income) 
{
   if (income <= 750.00f)
      return income * .01f;
   else if (income <= 2250.00f)
      return 7.50f + ((income - 750.00f) * .02f);
   else if (income <= 3750.00f)
      return 37.50f + ((income - 2250.00f) * .03f);
   else if (income <= 5250.00f)
      return 82.50f + ((income - 3750.00f) * .04f);
   else if (income <= 7000.00f)
      return 142.50f + ((income - 5250.00f) * .05f);
   else
      return 230.00f + ((income - 7000.00f) * .06f);
}
