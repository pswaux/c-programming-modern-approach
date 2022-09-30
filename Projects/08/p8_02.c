/**
 * 
 * Modify the repdiqit.c program of Section 8.1 so that it prints
 * a table showing how many times each digit appears in the number:
 *
 *    Enter a number: 41271092
 *    Digit:        0   1  2  3  4  5  6  7  8  9
 *    Occurrences:  1   2  2  0  1  0  0  1  0  1
 * 
 */
#include <stdio.h>

#define SIZE 10

int main(void)
{
   int number = 0;
   int digits[SIZE] = {0};

   printf("Enter a number: ");
   scanf("%d", &number);

   // find the occurrences of each individual digit
   for (; ;) {
      digits[number % 10]++;  // increase the count
      number /= 10;

      if (number == 0) break;
   }

   printf("Digit:\t\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
   printf("Occurrences:\t");
   for (int i = 0; i < SIZE; ++i)
      printf("%d\t", digits[i]);

   printf("\n");
   return 0;
}
