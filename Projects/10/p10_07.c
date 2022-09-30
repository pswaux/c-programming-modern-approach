/**
 *
 * Write a program that prompts the user for a number and then displays the number
 * using characters to simulate the effect of a seven-segment display:
 *
 *    Enter a number: 491-9014
 *
 *         _      _   _
 *    |_| |_|  | |_| | |   | |_|
 *      |  _|  |  _| |_|   |   |
 *
 * Characters other than digits should be ignored. Write the program so that the maximum
 * number of digits is controlled by a macro named MAX_DIGITS, which has the value 10. If
 * the number contains more than this number of digits, the extra digits are ignored.
 *
 * Hints: Use two external arrays. One is the segments array (see Exercise 6 in Chapter 8),
 * which stores data representing the correspondence between digits and segments. The other
 * array, digits, will be an array of characters with 4 rows (since each segmented digit is
 * four characters high) and MAX_DIGITS * 4 columns (digits are three characters wide, but a
 * space is needed between digits for readability).
 *
 * Write your program as four functions:
 *    main, clear_digits_array, process_digit, and print_digits_array. Here are the prototypes
 *    for the latter three functions:
 *
 *       void clear_digits_array(void);
 *       void process_digit(int digit, int position);
 *       void print_digits_array(void);
 *
 * clear_digits_array will store blank characters into all elements of the digits array.
 * process_digit will store the seven-segment representation of digit into a specified position
 * in the digits array (positions range from 0 to MAX_DIGITS - 1).
 * print_digits_array will display the rows of the digits array, each on a single line, producing
 * output such as that shown in the example.
 *
 */
#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS   10
#define ROW 4
#define COL (MAX_DIGITS * 4)
#define SEGMENT_NUMBER 7

/* external variables   */
const int segments[MAX_DIGITS][SEGMENT_NUMBER] = {
      {1, 1, 1, 1, 1, 1, 0},  // 0
      {0, 1, 1, 0, 0, 0, 0},  // 1
      {1, 1, 0, 1, 1, 0, 1},
      {1, 1, 1, 1, 0, 0, 1},
      {0, 1, 1, 0, 0, 1, 1},
      {1, 0, 1, 1, 0, 1, 1},
      {1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 1}   // 9
};

char digits[ROW][COL];

/* prototypes  */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   char ch = ' ';
   int digit_count = 0;
   int position = 1;

   clear_digits_array();
   printf("Enter a number: ");
   while (digit_count < MAX_DIGITS) {
      ch = getchar();

      if (ch == '\n') break;
      if (!isdigit(ch)) continue;

      process_digit(ch - '0', position);
      position += 4;
      digit_count++;
   }

   print_digits_array();
   printf("\n");
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void clear_digits_array(void)
// will store blank characters into all
// elements of the digits array
{
   for (int i = 0; i < ROW; i++)
      for (int j = 0; j < COL; j++)
         digits[i][j] = ' ';
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void process_digit(int digit, int position) 
// will store the seven-segment representation of digit 
// into a specified position in the digits array
{
   char segment_ch;
   int row;
   int orig_position = position;

   // check the segments whether they're "on" or not
   // and set the corresponding character to be displayed
   // also set the rows and position of the characters
   for (int segment = 0; segment < SEGMENT_NUMBER; segment++) {
      switch (segment) {
         case 0: row = 0; position = orig_position; break;
         case 1: row = 1; position++; break;
         case 2: row = 2; position++; break;
         case 3: row = 2; position = orig_position; break;
         case 4: row = 2; position--; break;
         case 5: row = 1; position--; break;
         case 6: row = 1; position= orig_position; break;
      }

      segment_ch = (segment % 3 == 0) ? '_' : '|';

      if (segments[digit][segment] == 0)
         digits[row][position] = ' ';
      else
         digits[row][position] = segment_ch;

      position = orig_position; // reset the position

   }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void print_digits_array(void) 
// will display the rows of the digits array
// each on a single line.
{
   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++)
         printf("%c", digits[i][j]);

      printf("\n");
   }
}
