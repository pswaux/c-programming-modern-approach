/**
 *
 * Modify Programming Project 14 from Chapter 8 so that it uses a pointer
 * instead of an integer to keep track of the current position in the array
 * that contains the sentence.
 *
 */
#include <stdio.h>
#include <ctype.h>

#define SIZE 50

int main(void)
{
   char sentence[SIZE], *ptr, *space;
   char ch;
   int length = 0;

   printf("Enter a sentence: ");
   for (int i = 0; i < SIZE; i++) {
      ch = getchar();
      if (ch == '.' || ch == '?' || ch == '!')
         break;

      sentence[i] = ch;
      length++;
   }

   printf("Reversal of sentence: ");
   for (space = sentence + length - 1; space >= sentence ; space--) {
      // find the last occurrences of the space character
      if (*space != ' ') continue;

      // space+1 indicates the first character of the word
      // since *space indicates the space character
      for (ptr = space + 1; ptr < sentence + length; ptr++)
         putchar(*ptr);          // put the word
      putchar(*space);           // put the space
      length = space - sentence; // set the length as index of the last space
   }

   for (ptr = sentence; ptr < sentence + length; ptr++) // put the last word
      putchar(*ptr);
   putchar(ch);                     // put the terminating character

   printf("\n");
   return 0;
}
