/**
 *
 * Modify the upc.c program of Section 4.1 so that
 * it checks whether a UPC is valid. After the user
 * enters a UPC, the program will display either
 * VALID or NOT VALID.
 * 
 */

#include <stdio.h>

int main(void) 
{
   int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
		first_sum, second_sum, total, check_digit, check;

	printf("Enter the first (single) digit: ");
	scanf("%1d", &d);

	printf("Enter first group of five digit: ");
	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

	printf("Enter second group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

   printf("Enter the check digit: ");
   scanf("%1d", &check_digit);

	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 3 * first_sum + second_sum;
   check = 9 - ((total - 1) % 10);

   if (check_digit == check)
      printf("VALID\n");
   else 
      printf("NOT VALID\n");

   return 0;
}
