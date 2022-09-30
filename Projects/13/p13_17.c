/**
 *
 * Modify Programming Project 2 from Chapter 12 so that it 
 * includes the following function:
 *
 *       bool is_palindrome(const char *message);
 *
 * The function returns true if the string pointed to by 
 * message is a palindrome.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 80

/* prototypes */
bool is_palindrome(const char *message);
int read_line(char str[], int n);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   char message[SIZE];

   printf("Enter a message: ");
   read_line(message, SIZE);

   if (is_palindrome(message))
      printf("Palindrome\n");
   else
      printf("Not a palindrome\n");

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool is_palindrome(const char *message)
{
   for (int i = 0, j = strlen(message) - 1; i <= j; i++, j--) {
      if (*(message + i) != *(message + j))
         return false;
   }

   return true;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int read_line(char str[], int n)
{
   int ch, i = 0;

   while ((ch = getchar()) != '\n') {
      if (!isalpha(ch)) continue;

      if (i < n)
         str[i++] = tolower(ch);
   }
   str[i] = '\0';

   return i;
}
