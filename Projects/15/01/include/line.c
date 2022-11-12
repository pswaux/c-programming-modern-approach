#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../include/line.h"

#define MAX_LINE_LEN 60
#define LEFT_JUSTIFIED true

/**
 * for example;
 * first line has 46 characters and 14 extra spaces.
 * 9 words = 8 spaces + 14 extra spaces = 22 spaces
 *         = 22 / 9 = 2 spaces will be inserted to the beginning
 * .
 * .
 * 1 word = 0 spaces + 1 extra spaces = 1 space
 *        = 1 / 1 = 1 space will be inserted to the end of the line
 * 
 */
#define SPACES(bool_exp, extra_spaces, num_words)                    \
   (bool_exp) ? ((extra_spaces) + ((num_words) - 1)) / (num_words)   \
              : ((extra_spaces) / ((num_words) - 1))

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void clear_line(void)
{
   line[0] = '\0';
   line_len = 0;
   num_words = 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void add_word(const char *word)
{
   if (num_words > 0) {
      line[line_len] = ' ';
      line[line_len + 1] = '\0';
      line_len++;
   }

   strcat(line, word);
   line_len += strlen(word);
   num_words++;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int space_remaining(void)
{
   return MAX_LINE_LEN - line_len;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void write_line(void)
{
   int extra_spaces, spaces_to_insert, i, j;

   extra_spaces = space_remaining();
   for (i = 0; i < line_len; i++) {
      if (line[i] != ' ')
         putchar(line[i]);
      else {
         spaces_to_insert = SPACES(LEFT_JUSTIFIED, extra_spaces, num_words);
         for (j = 1; j <= spaces_to_insert + 1; j++)
            putchar(' ');
         extra_spaces -= spaces_to_insert;
         num_words--;
      }
   }
   putchar('\n');
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void flush_line(void)
{
   if (line_len > 0)
      puts(line);
}
