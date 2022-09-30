/**
 *
 * The value of the mathematical constant 'e' can be expressed
 * as an infinite series:
 *
 *    e = 1 + 1/1! + 1/2! + 1/3! + ...
 *
 * Write a program that approximates e by computing the value of
 *    1 + 1/1! + 1/2! + 1/3! + 1/n!
 * where n is an integer entered by the user
 *
 */
#include <stdio.h>

int main(void)
{
   int n = 0;
   float e = 1.0f;  // 0! = 1
   int factorial = 1;

   printf("Enter a number: ");
   scanf("%d", &n);

   for (int i = 1; i <= n; i++) {
      /* find the factorial of i */
      for (int j = i; j >= 1; j--)
         factorial *= j;

      e += 1.0f / factorial;
      factorial = 1; // reset the factorial
   }

   printf("e is approximately equal to: %.5f\n", e);
}
