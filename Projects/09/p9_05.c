/**
 *
 * Modify Programming Project 17 from Chapter 8 so that it includes
 * the following functions:
 *
 *    void create_magic_square(int n, int magic_square[n][n]);
 *    void print_magic_square(int n, int magic_square[n][n]);
 *
 * After obtaining the number n from the user, main will call
 * create_magic_square, passing it an n x n array that is declared
 * inside main. create magic square will fill the array with the numbers
 * 1, 2, ....n² as described in the original project. main will then call
 * print_magic_square, which will display the array in the format described
 * in the original project.
 *
 * Note: If your compiler doesn’t support variable-length arrays, declare the
 * array in main to be 99 x 99 instead of n x n and use the following prototypes
 * instead:
 *
 *    void create_magic_square(int n, char magic_square[99][99]);
 *    void print_magic_square(int n, char magic_square[99][99]);
 *
 *
 */
#include <stdio.h>

/* prototypes  */
void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   int size;

   printf("\nThis program creates a magic square of a specified size.");
   printf("\nThe size must be an odd number between 1 and 99.");
   printf("\nEnter size of magic square: ");
   scanf("%d", &size);

   /* declare and initialize the array */
   int square[size][size];
   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++)
         square[i][j] = 0;
   }

   create_magic_square(size, square);
   print_magic_square(size, square);

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void create_magic_square(int n, int magic_square[n][n])
{
   int row = 0;
   int col = n / 2;
   int number = 1;

   magic_square[row][col] = number++;
   while (number <= n * n) {
      // if we say, row is 0 and size is 5 then row - 1;
      // (0 - 1 + 5) % 5 will be 4
      row = ((row - 1) + n) % n;
      col = (col + 1) % n;

      if (magic_square[row][col] == 0)       // move available
         magic_square[row][col] = number;
      else {                           // no move, go down by one row
         row = (row + 2) % n;          // restore the row to previous location and increase 1
         col = ((col - 1) + n) % n;    // restore the col

         magic_square[row][col] = number;
      }

      number++;
   }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void print_magic_square(int n, int magic_square[n][n]) 
{
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         printf("%5d", magic_square[i][j]);
      }

      printf("\n");
   }
}

