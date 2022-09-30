/**
 *
 * (a) Write a program that reads a message, then prints the reversal of the message:
 *
 *    Enter a message: Don't get mad, get even.
 *    Reversal is: .neve teg, dam teg t'noD
 *
 * Hint: Read the message one character at a time (using getchar) and
 * store the characters in an array. Stop reading when the array is full
 * or the character read is '\n'.
 *
 * (b) Revise the program to use a pointer instead of an integer to keep
 * track of the current position in the array.
 *
 */
#include <stdio.h>

#define SIZE 80

int main(void) 
{
   char message[SIZE];
   char ch;
   int length = 0;

   printf("Enter a message: ");
   for (int i = 0; i < SIZE; i++) {
      ch = getchar();

      if (ch == '\n') break;

      message[i] = ch;
      length++;
   }

   printf("Reversal is: ");
   for (int i = length - 1; i >= 0; i--)
      putchar(message[i]);

   printf("\n");
   return 0;
}
