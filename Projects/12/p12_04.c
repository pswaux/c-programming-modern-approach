/**
 *
 * (a) Write a program that reads a message, then checks whether it's a palindrome
 * (the letters in the message are the same from left to right as from right to left):
 *
 *    Enter a message: He lived as a devil, eh?
 *    Palindrome
 *
 *    Enter a message: Madam, I am Adam.
 *    Not a palindrome
 *
 * Ignore all characters that aren't letters. Use integer variables to keep track of
 * positions in the array.
 *
 * (b) Revise the program to use pointers instead of integers to keep track of
 * positions in the array
 *
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 80

int main(void) 
{
   char message[SIZE];
   char ch, *ptr_first, *ptr_last;
   int length = 0;
   bool is_palindrome = false;

   printf("Enter a message: ");
   for (; ;) {
      ch = getchar();

      if (ch == '\n' || length == SIZE) break;

      if (isalpha(ch))
         message[length++] = tolower(ch);
   }

   for (ptr_first = message, ptr_last = message + length - 1; ptr_first < ptr_last; ptr_first++, ptr_last--) {
      if (*ptr_first == *ptr_last)
         is_palindrome = true;
      else {
         is_palindrome = false;
         break;
      }
   }

   if (is_palindrome)
      printf("Palindrome\n");
   else
      printf("Not a palindrome\n");

   return 0;
}
