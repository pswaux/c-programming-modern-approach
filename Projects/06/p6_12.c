/**
 *
 * Modify Programming Project 11 so that the program continues
 * adding terms until the current term becomes less than €, 
 * where € is a small (floating-point) number entered by the user.
 *
 */
#include <stdio.h>

int main(void) 
{
   float n = 0.0f;
   float e = 1.0f;  // 0! = 1
   int factorial = 1;
   float term = 1.0f;

   printf("Enter a number: ");
   scanf("%f", &n);

   for (int i = 1; ; i++) {
      /* find the factorial of i */
      for (int j = i; j >= 1; j--)
         factorial *= j;

      term = 1.0f / factorial;
      if (term >= n) {
         e += term;
         factorial = 1; // reset the factorial
      } else
         break;      
   }

   printf("e is approximately equal to: %.5f\n", e);
}
