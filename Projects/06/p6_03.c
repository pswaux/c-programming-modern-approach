/**
 *
 * Write a program that asks the user to enter a fraction
 * then reduces the fraction to lowest terms:
 *
 *    Enter a fraction: 6/12
 *    In lowest terms: 1/2
 *
 * Hint: To reduce a fraction to lowest terms, first compute the GCD
 * of the numerator and denominator. Then divide both the numerator
 * and denominator by the GCD.
 *
 */
#include <stdio.h>

int main(void)
{
   int numerator, denominator, gcd, remainder, divisor;

   printf("Enter a fraction: ");
   scanf("%d/%d", &numerator, &denominator);

   divisor = denominator;
   gcd = numerator;
   while (divisor != 0) {
      remainder = gcd % divisor;
      gcd = divisor;
      divisor = remainder;
   }

   printf("In lowers terms: %d/%d\n", numerator/gcd, denominator/gcd);

   return 0;
}
