/**
 *
 * Write a program that prints the values of sizeof(int),
 * sizeof(short), sizeof(long), sizeof(float), sizeof(double)
 * and sizeof(long double).
 *
 */
#include <stdio.h>

int main(void)
{
   printf("The size of short: %lu\n", sizeof(short));
   printf("The size of int: %lu\n", sizeof(int));
   printf("The size of long: %lu\n", sizeof(long));
   printf("The size of float: %lu\n", sizeof(float));
   printf("The size of double: %lu\n", sizeof(double));
   printf("The size of long double: %lu\n", sizeof(long double));

   return 0;
}
