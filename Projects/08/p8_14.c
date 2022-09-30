/**
 * 
 * Write a program that reverses the words in a sentence:
 *
 *    Enter a sentence: you can cage a swallow can't you?
 *    Reversal of sentence: you can't swallow a cage can you?
 *
 * Hint: Use a loop to read the characters one by one and store
 * them in a one-dimensional char array. Have the loop stop at a
 * period, question mark, or exclamation point (the “terminating character”),
 * which is saved in a separate char variable. Then use a second loop to search
 * backward through the array for the beginning of the last word. Print the
 * last word, then search backward for the next-to-last word. Repeat until the
 * beginning of the array is reached. Finally, print the terminating character.
 * 
 */
#include <stdio.h>
#include <ctype.h>

#define SIZE 50

int main(void)
{
   char sentence[SIZE];
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
   for (int i = length-1; i >= 0 ; i--) {
      // find the last occurrences of the space character
      if (sentence[i] != ' ') continue;

      // i+1 indicates the first character of the word
      // since i indicates the space character
      for (int j = i + 1; j < length; j++)
         putchar(sentence[j]);   // put the word
      putchar(sentence[i]);      // put the space
      length = i;                // set the length as index of the last space
   }

   for (int i = 0; i < length; i++) // put the last word
      putchar(sentence[i]);
   putchar(ch);                     // put the terminating character

   printf("\n");
   return 0;
}
