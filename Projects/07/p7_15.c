/**
 *
 * Write a program that computes the factorial of a positive integer:
 *
 *    Enter a positive integer: 6
 *    Factorial of 6: 720
 *
 * (a) Use a short variable to store the value of the factorial.
 *     What is the largest value of n for which the program correctly
 *     prints the factorial of n?
 * (b) Repeat part (a), using an int variable instead.
 * (c) Repeat part (a), using an long variable instead.
 * (d) Repeat part (a), using an long long variable instead.
 * (e) Repeat part (a), using an float variable instead.
 * (f) Repeat part (a), using an double variable instead.
 * (g) Repeat part (a), using an long double variable instead.
 *
 */
#include <stdio.h>

int main(void) 
{
   //short number, factorial = 1;
   //int number, factorial = 1;
   //long number, factorial = 1L;
   //long long number, factorial = 1LL;
   //float number, factorial = 1.0f;
   //double number, factorial = 1.0;
   long double number, factorial = 1.0L;

   printf("Enter a positive integer: ");
   scanf("%Lf", &number);

   for (int i = number; i > 1; i--)
      factorial *= i;

   printf("Factorial of %.2Lf: %.2Lf\n", number, factorial);
   return 0;
}

// short       -> 7
// int         -> 16
// long        -> 25
// long long   -> 25
// float       -> 34
// double      -> 170
// long double -> 1754
