/**
 *
 * Modify Programming Project 14 from Chapter 8 so that it stores the words in a 
 * two-dimensional char array as it reads the sentence, with each row of the array 
 * storing a single word. Assume that the sentence contains no more than 30 words and 
 * no word is more than 20 characters long. Be sure to store a null character at the 
 * end of each word so that it can be treated as a string.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_NUM 30
#define WORD_LEN 21

/* prototypes  */
void print_reverse(char sentence[][WORD_LEN], int size);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   char sentence[WORD_NUM][WORD_LEN];
   char ch;
   int word_count = 0, i, j;

   printf("Enter a sentence: ");
   for (i = 0; i < WORD_NUM; i++) {
      j = 0;
      for ( ; j < WORD_LEN; j++) { 
         ch = getchar();

         if (j == WORD_LEN - 1)
            ch = '\0';

         if (ch == ' ') {
            *(sentence[i] + j) = '\0';
            word_count++;
            break;
         } else if (ch == '.' || ch == '?' || ch == '!') {
            *(sentence[i] + j) = '\0';
            i = WORD_NUM;  // exit from the outer loop
            break;
         } else
            *(sentence[i] + j) = ch;
      }
   }

   print_reverse(sentence, word_count);
   putchar(ch); //put the terminating character

   printf("\n");
   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void print_reverse(char sentence[][WORD_LEN], int size)
{
   printf("Reversal of sentence: ");
   for (int i = size; i >= 0; i--) {
      if (i != 0)
         strcat(sentence[i], " ");
      printf("%s", sentence[i]);
   }
}
