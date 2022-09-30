/**
 *
 * Write a program that finds the “smallest” and “largest” in a senes of words. After the user
 * enters the words, the program will determine which words would come first and last if the
 * words were listed in dictionary order. The program must stop accepting input when the user
 * enters a four-letter word. Assume that no word is more than 20 letters long. An interactive
 * session with the program might look like this:
 *
 *       Enterword: dog
 *       Enterword: zebra
 *       Enterword: rabbit
 *       Enterword: catfish
 *       Enterword: walrus
 *       Enterword: cat
 *       Enterword: fish
 *
 *       Smallest word: cat
 *       Largest word: zebra
 *
 * Hint: Use two strings named smallest_word and largest_word to keep track of the
 * “smallest” and “largest” words entered so far. Each time the user enters a new word, use
 * strcmp to compare it with smallest_word; if the new word is “smaller,” use strcpy to save 
 * it in smallest_word. Do a similar comparison with largest_word. Use strlen to determine when 
 * the user has entered a four-letter word.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_LENGTH 20

/* prototypes  */
int read_line(char str[], int n);
void find_smallest(const char word[], char smallest[]);
void find_largest(const char word[], char largest[]);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   char word[WORD_LENGTH + 1];
   char smallest_word[WORD_LENGTH + 1] = "z";
   char largest_word[WORD_LENGTH + 1] = "a";

   while (true) {
      printf("Enter word: ");
      read_line(word, WORD_LENGTH);

      if (strlen(word) == 4)
         break;

      if (strcmp(word, smallest_word) < 0)
         strcpy(smallest_word, word);
      
      if (strcmp(word, largest_word) > 0)
         strcpy(largest_word, word);
      
      //find_smallest(word, smallest_word);
      //find_largest(word, largest_word);
   }

   printf("\nSmallest word: %s\n", smallest_word);
   printf("Largest word: %s\n", largest_word);     
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

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void find_smallest(const char word[], char smallest[])
{
   if (strcmp(word, smallest) < 0)
      strcpy(smallest, word);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void find_largest(const char word[], char largest[])
{
   if (strcmp(word, largest) >= 0)
      strcpy(largest, word);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
