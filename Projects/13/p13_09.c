/**
 *
 * Modify Programming Project 10 from Chapter 7 so that it includes the following function:
 * 
 *       int compute_vowel_count(const char *sentence);
 *
 * The function returns the number of vowels in the string pointed to by the sentence
 * parameter.
 *
 */
#include <stdio.h>
#include <ctype.h>

#define LENGTH 80

/* prototypes  */
int compute_vowel_count(const char *sentence);
int read_line(char str[], int n);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   char sentence[LENGTH];

   printf("Enter a sentence: ");
   read_line(sentence, LENGTH);

   printf("You sentence contains %d vowels\n", compute_vowel_count(sentence)); 
   
   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int compute_vowel_count(const char *sentence)
{
   int count = 0;

   for (int i = 0; sentence[i] != '\0'; i++) {
      switch (toupper(sentence[i])) {
         case 'A': case 'E': case 'I': case 'O':
         case 'U':
            count++;
            break;
      }
   }

   return count;
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
