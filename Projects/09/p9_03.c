/**
 *
 * Modify Programming Project 9 from Chapter 8 so that it
 * includes the following functions:
 *
 *    void generate_random_walk(char walk[10][10]);
 *    void print_array(char walk[10][10]);
 *
 * main first calls generate_random_walk, which initializes
 * the array to contain '.' characters and then replaces some
 * of these characters by the letters A through Z, as described
 * in the original project. main then calls print array to display
 * the array on the screen.
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

/* prototypes  */
void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   char board[SIZE][SIZE];

   generate_random_walk(board);
   print_array(board);

   printf("\n");
   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void generate_random_walk(char walk[10][10])
{
   bool check[SIZE][SIZE];
   int row, col;
   int prev_row, prev_col; // previous location
   char letter = 'A';
   int move;

   // initialize the arrays
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         walk[i][j] = '.';
         check[i][j] = true;
      }
   }

   // set the starting point
   srand((unsigned) time(NULL));
   row = rand() % SIZE;
   col = rand() % SIZE;

   walk[row][col] = letter++;
   check[row][col] = false;

   for (;;) {
      // decide the move
      // 0 - UP      (row--)
      // 1 - RIGHT   (col++)
      // 2 - DOWN    (row++)
      // 3 - LEFT    (col--)
      move = rand() % 4;

      // check the boundaries of the board
      if ((row == 0 && move == UP) || (row == 9 && move == DOWN)
            || (col == 0 && move == LEFT) || (col == 9 && move == RIGHT))
         continue; // no move, choose again

      prev_row = row;
      prev_col = col;
      switch (move) {
         case UP:
            row--;
            break;
         case RIGHT:
            col++;
            break;
         case DOWN:
            row++;
            break;
         case LEFT:
            col--;
            break;
      }

      // check whether the move is available
      // if not, choose again
      if (!check[row][col]) {   // there's no available move
         // restore the original location
         row = prev_row;
         col = prev_col;
         continue;
      } else {
         walk[row][col] = letter++;
         check[row][col] = false;
      }

      // quit or continue?
      if (letter > 'Z')
         break;
      if (!check[row + 1][col] && !check[row - 1][col] && !check[row][col + 1]
            && !check[row][col - 1])
         break;
   }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void print_array(char walk[10][10])
{
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++)
         printf("%3c", walk[i][j]);

      printf("\n");
   }
}

