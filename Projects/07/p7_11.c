/**
 *
 * Write a program that takes a first name and last name
 * entered by the user and displays the last name, a comma,
 * and the first initial, followed by a period:
 * 
 *    Enter a first and last name: Lloyd Fosdick
 *    Fosdick, L.
 *
 * The user's input may contain extra spaces before the first name,
 * between the first and last names, and after the last name.
 * 
 */
#include <stdio.h>

int main(void)
{
   char first, last;
   
   printf("Enter a first and last name: ");
   scanf(" %c", &first);      // get the first character
   // and skip the rest of the characters
   while (getchar() != ' ');

   scanf(" %c", &last);
   while (last != '\n') {
      putchar(last);
      scanf("%c", &last);
   }

   printf(", %c.\n", first);

   return 0;
}
