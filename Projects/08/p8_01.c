/**
 * 
 * Modify the repdigit.c program of Section 8.1 so that
 * it shows which digits (if any) were repeated:
 *
 *    Enter a number: 939577
 *    Repeated digit(s): 7 9
 * 
 */
#include <stdio.h>

#define SIZE 10

int main(void)
{
   int digits[SIZE] = {0};
   int number = 0;

   printf("Enter a number: ");
   scanf("%d", &number);

   for (; ;) {
      digits[number % 10]++;  // increase the digit's count

      number /= 10;
      if (number == 0) break;
   }

   printf("Repeated digit(s): ");
   for (int i = 0; i < SIZE; i++) {
      if (digits[i] > 1)   // repeated digit
         printf("%d ", i);
   }

   printf("\n");
}
