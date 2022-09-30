/**
 * 
 * Write a program that reads a 5 x 5 array of integers and
 * then prints the row sums and the column sums:
 *
 *    Enter row 1: 8 3 9 0 10
 *    Enter row 2: 3 5 17 1 1
 *    Enter row 3: 2 8 6 23 1
 *    Enter row 4: 15 7 3 2 9
 *    Enter row 5: 6 14 2 6 0
 *
 *    Row totals:    30 27 40 36 28
 *    Column totals: 34 37 37 32 21
 * 
 */
#include <stdio.h>

#define SIZE 5

int main(void)
{
   int arr[SIZE][SIZE];
   int row, col, row_sum = 0, col_sum = 0;

   /* initialize the array */
   for (row = 0; row < SIZE; row++) {
      printf("Enter row %d: ", row + 1);

      for (col = 0; col < SIZE; col++)
         scanf("%d", &arr[row][col]);
   }

   printf("\nRow totals: ");
   for (row = 0; row < SIZE; row++) {
      for (col = 0; col < SIZE; col++)
         row_sum += arr[row][col];

      printf("%4d", row_sum);
      row_sum = 0;   // reset the total at every iteration
   }

   printf("\nColumn totals: ");
      for (row = 0; row < SIZE; row++) {
         for (col = 0; col < SIZE; col++)
            col_sum += arr[col][row];

         printf("%4d", col_sum);
         col_sum = 0;
      }

      printf("\n");
      return 0;
}
