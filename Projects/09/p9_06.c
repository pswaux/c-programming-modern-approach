/**
 *
 * Write a function that computes the value of the following polynomial:
 *
 *    3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6
 *
 * Write a program that asks the user to enter a value for x, calls the
 * function to compute the value of the polynomial, and then displays the
 * value returned by the function.
 *
 */
#include <stdio.h>

/* prototype   */
int compute_polynom(int);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   int x;

   printf("Please enter polynomial's variable (x): ");
   scanf("%d", &x);

   printf("The value of polynomial: %d\n", compute_polynom(x));
   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int compute_polynom(int x)
{
   return (3 * x * x * x * x * x) +
           (2 * x * x * x * x) -
            (5 * x * x * x) -
             (x * x) +
              (7 * x) -
                6;
}
