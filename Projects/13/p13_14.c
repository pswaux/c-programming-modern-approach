/**
 *
 * Modify Programming Project 16 from Chapter 8 so that it includes 
 * the following function: 
 *
 *       bool are_anagrams(const char *word1, const char *word2);
 *
 * The function returns true if the strings pointed to by word1 and 
 * word2 are anagrams.
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 26

/* prototypes */
int read_line(char str[], int n);
bool are_anagrams(const char *word1, const char *word2);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   char word1[SIZE];
   char word2[SIZE];

   printf("Enter first word: ");
   read_line(word1, SIZE);

   printf("Enter second word: ");
   read_line(word2, SIZE);

   if (are_anagrams(word1, word2))
      printf("The words are anagram\n");
   else
      printf("The words are not anagram\n");
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int read_line(char str[], int n)
{
   int ch, i = 0;

   while ((ch = getchar()) != '\n') {
      if (!isalpha(ch))
         continue;

      if (i < n)
         str[i++] = ch;
   }
   str[i] = '\0';

   return i;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool are_anagrams(const char *word1, const char *word2)
{
   int letters[SIZE] = {0};

   while (*word1)
      letters[tolower(*word1++) - 'a']++;

   while (*word2)
      letters[tolower(*word2++) - 'a']--;

   for (int i = 0; i < SIZE; i++) {
      if (letters[i] != 0)
         return false;
   }

   return true;   
}
