/**
 * 
 * Write a program that generates a “random walk” across a 10 x 10 array.
 * The array will contain characters (all '.' initially). The program must
 * randomly “walk” from element to element, always going up, down, left. or
 * right by one element. The elements visited by the program will be labeled
 * with the letters A through Z, in the order visited. Here's an example of
 * the desired output:
 *
 *    A  .  .  .  .  .  .  .  .  .
 *    B  C  D  .  .  .  .  .  .  .
 *    .  F  E  .  .  .  .  .  .  .
 *    H  G  .  .  .  .  .  .  .  .
 *    I  .  .  .  .  .  .  .  .  .
 *    J  .  .  .  .  .  .  .  Z  .
 *    K  .  .  R  S  T  U  V  Y  .
 *    L  M  P  Q  .  .  .  W  X  .
 *    .  N  O  .  .  .  .  .  .  .
 *    .  .  .  .  .  .  .  .  .  .
 *
 * Hint: Use the srand and rand functions (see deal.c) to generate random numbers.
 * After generating a number, look at its remainder when divided by 4. There are four
 * possible values for the remainder — O, 1, 2, and 3— indicating the direction of the
 * next move. Before performing a move, check that (a) it won't go outside the array, and
 * (b) it doesn't take us to an element that already has a letter assigned. If either condition
 * is violated, try moving in another direction. If all four directions are blocked, the
 * program must terminate. Here's an example of premature termination:
 * 
 *    A  B  G  H  I  .  .  .  .  .
 *    .  C  F  .  J  K  .  .  .  .
 *    .  D  E  .  M  L  .  .  .  .
 *    .  G  .  .  N  O  .  .  .  .
 *    .  .  W  X  Y  P  Q  .  .  .
 *    .  .  V  U  T  S  R  .  .  .
 *    .  .  .  .  .  .  .  .  .  .
 *    .  .  .  .  .  .  .  .  .  .
 *    .  .  .  .  .  .  .  .  .  .
 *    .  .  .  .  .  .  .  .  .  .
 *
 *    Y is blocked on all four sides. so there's no place to put Z.
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE   10
#define UP     0
#define RIGHT  1
#define DOWN   2
#define LEFT   3

int main(void)
{
   char board[SIZE][SIZE];
   bool check[SIZE][SIZE];
   int row, col;
   int prev_row, prev_col; // previous location
   char letter = 'A';
   int move;

   // initialize the arrays
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         board[i][j] = '.';
         check[i][j] = true;
      }
   }

   // set the starting point
   srand((unsigned) time(NULL));
   row = rand() % SIZE;
   col = rand() % SIZE;

   board[row][col] = letter++;
   check[row][col] = false;

   for (; ;) {
      // decide the move
      // 0 - UP      (row--)
      // 1 - RIGHT   (col++)
      // 2 - DOWN    (row++)
      // 3 - LEFT    (col--)
      move = rand() % 4;

      // check the boundaries of the board
      if ((row == 0 && move == UP)    ||
          (row == 9 && move == DOWN)  ||
          (col == 0 && move == LEFT)  ||
          (col == 9 && move == RIGHT))
         continue; // no move, choose again

      prev_row = row;
      prev_col = col;
      switch (move) {
         case UP:    row--; break;
         case RIGHT: col++; break;
         case DOWN:  row++; break;
         case LEFT:  col--; break;
      }

      // check whether the move is available
      // if not, choose again
      if (!check[row][col]) {   // there's no available move
         // restore the original location
         row = prev_row;
         col = prev_col;
         continue;
      } else {
         board[row][col] = letter++;
         check[row][col] = false;
      }

      // quit or continue?
      if (letter > 'Z') break;
      if (!check[row+1][col] && !check[row-1][col] &&
          !check[row][col+1] && !check[row][col-1])
         break;
   }

   // draw the board
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++)
         printf("%3c", board[i][j]);

      printf("\n");
   }

   printf("\n");
   return 0;
}
