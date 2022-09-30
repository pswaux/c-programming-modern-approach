/**
 *
 * Modify Programming Project 13 trom Chapter 7 so that it includes
 * the following function:
 *
 *       double compute_average_word_length(const char *sentence);
 *
 * The function returns the average length of the words in the string 
 * pointed to by sentence.
 *
 */
#include <stdio.h>

#define LENGTH 80

/* prototypes  */
double compute_average_word_length(const char *sentence);
int read_line(char str[], int n);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   char sentence[LENGTH];

   printf("Enter a sentence: ");
   read_line(sentence, LENGTH);

   printf("Average word length: %.1f\n", compute_average_word_length(sentence));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

double compute_average_word_length(const char *sentence)
{
   int length = 0;
   int word_count = 0;

    for (int i = 0; *(sentence + i); i++) {
      length++;

      if (*(sentence + i) == ' ') {
         word_count++;
         length--;      // subtract the space from total length
      }
   }

   word_count++;                 // add the last word

   return (double)length / word_count;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int read_line(char str[], int n)
{
   int ch, i = 0;

   while ((ch = getchar()) != '\n')
      if (i < n)
         str[i++] = ch;
   str[i] = '\0';

   return i;
}
