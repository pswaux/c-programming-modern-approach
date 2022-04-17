/**
 *
 * Write a program that calculates the average word length
 * for a sentence:
 *
 *    Enter a sentence: It was deja vu all over again.
 *    Average word length: 3.4
 *
 * For simplicity, your program should consider a punctuation mark
 * to be part of the word to which it is attached. Display the average
 * word length to one decimal place.
 *
 */
#include <stdio.h>

int main(void) {
   char ch;
   int word_count = 0, len = 0;

   printf("Enter a sentence: ");
   for (; ;) {
      ch = getchar();
      len++;

      if (ch == ' ')
         word_count++;
      
      if (ch == '\n') {
         word_count++;  // add the last word
         len--;         // subtract the new line
         break;
      }
   }

   len -= (word_count - 1);   // subtract the spaces from total length


   printf("%d\n", len);
   printf("%d\n", word_count);
   printf("Average word length: %.1f\n", (float)len / word_count);
}