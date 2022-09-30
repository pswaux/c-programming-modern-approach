/**
 *
 * Write a program that finds the largest and smallest of
 * four integers entered by the user:
 *
 *    Enter four integers: 21 43 10 35
 *    Largest: 43
 *    Smallest: 10
 *
 * Use as few if statements as possible. Hint; Four if statements are sufficient.
 *
 */

#include <stdio.h>

int main(void) 
{
   int num1, num2, num3, num4;
   int min, max;

   printf("Enter four integers: ");
   scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

   if (num1 <= num2) {
      min = num1;
      max = num2;
   }
   else {
      min = num2;
      max = num1;
   }

   if (num3 > max) {
      max = num3;
   } else if (num3 < min)
      min = num3;

   if (num4 > max) {
      max = num4;
   } else if (num4 < min)
      min = num4;

   printf("Largest: %d\n", max);
   printf("Smallest: %d\n", min);

   return 0;
}
