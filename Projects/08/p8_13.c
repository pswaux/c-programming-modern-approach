/**
 * 
 * Modify Programming Project 11 from Chapter 7 so that
 * the program labels its output:
 *
 *    Enter a first and last name: Lloyd Fosdick
 *    You entered the name: Fosdick, L.
 *
 * The program will need to store the last name (but not the first name)
 * in an array of characters until it can be printed.
 * You may assume that the last name is no more than 20 characters long.
 * 
 */
#include <stdio.h>
#include <ctype.h>

#define SIZE 20

int main(void)
{
   char ch, first, last[SIZE];
   int len = 0;

   printf("Enter a first and last name: ");
   scanf(" %c", &first);      // get the first character
   while (getchar() != ' ');  // and skip the rest of the characters

   for (int i = 0; i < SIZE; i++) {
      ch = getchar();
      if (ch == '\n')
         break;

      last[i] = ch;
      len++;
   }

   for (int i = 0; i < len; i++)
      putchar(last[i]);

   printf(", %c.\n", first);
   return 0;
}
