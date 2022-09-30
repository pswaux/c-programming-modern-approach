/**
 *
 * Modify Programming Project 16 from Chapter 8 so that it
 * includes the following functions:
 *
 *    void read_word(int counts[26]);
 *    bool equal_array(int counts1[26], int counts2[26]);
 *
 * main will call read_word twice, once for each of the two words
 * entered by the user. As it reads a word, read word will use the
 * letters in the word to update the counts array, as described in
 * the original project. (main will declare two arrays, one for each word.
 * These arrays are used to track how many times each letter occurs in the
 * words.) main will then call equal_array, passing it the two arrays.
 * equal_array will return true if the elements in the two arrays are identical
 * (indicating that the words are anagrams) and false otherwise.
 *
 *
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 26

/* prototypes  */
void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   int word1[SIZE] = { 0 };
   int word2[SIZE] = { 0 };

   printf("Enter first word: ");
   read_word(word1);

   printf("Enter second word: ");
   read_word(word2);

   if (equal_array(word1, word2))
      printf("The words are anagram\n");
   else
      printf("The words are not anagram\n");

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void read_word(int counts[26])
{
   char ch;
   while (true) {
      ch = getchar();
      if (ch == '\n')
         break;

      if (!isalpha(ch))
         continue;

      counts[tolower(ch) - 'a']++;
   }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool equal_array(int counts1[26], int counts2[26])
{
   bool is_anagram = true;

   for (int i = 0; i < 26; i++) {
      if (counts1[i] != counts2[i]) {
         is_anagram = false;
      }
   }

   return is_anagram;
}
