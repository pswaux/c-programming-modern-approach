/**
 *
 * Modify Programming Project 3 from Chapter 6 so that it includes the following function:
 *
 *    void reduce(int numerator, int denominator,
 *                int *reduced_numerator,
 *                int *reduced_denominator);
 *
 * numerator and denominator are the numerator and denominator of a fraction.
 * reduced_numerator and reduced_denominator are pointers to variables in
 * which the function will store the numerator and denominator of the fraction
 * once it has been reduced to lowest terms.
 *
 */
#include <stdio.h>

void reduce(int, int, int *, int *);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   int numerator, denominator, reduced_numerator, reduced_denominator;

   printf("Enter a fraction: ");
   scanf("%d/%d", &numerator, &denominator);

   reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
   printf("In lowers terms: %d/%d\n", reduced_numerator, reduced_denominator);

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
   int gcd, remainder, divisor;

   // first, find the GCD
   divisor = denominator;
   gcd = numerator;
   while (divisor != 0) {
      remainder = gcd % divisor;
      gcd = divisor;
      divisor = remainder;
   }

   *reduced_numerator = numerator / gcd;
   *reduced_denominator = denominator / gcd;
}
