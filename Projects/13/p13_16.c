/**
 *
 * Modify Programming Project 1 from Chapter 12 so that it includes 
 * the following function:
 *
 *       void reverse(char *message);
 *
 * The function reverses the string pointed to by message. 
 * Hint: Use two pointers, one initially pointing to the first character 
 * of the string and the other initially pointing to the last character. 
 * Have the function reverse these characters and then move the pointers 
 * toward each other, repeating the process until the pointers meet.
 *
 */
#include <stdio.h>
#include <string.h>

#define SIZE 80

/* prototypes */
void reverse(char *message);
int read_line(char str[], int n);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   char message[SIZE];

   printf("Enter a message: ");
   read_line(message, SIZE);

   printf("Reversal is: ");
   reverse(message);

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void reverse(char *message)
{
   char *first_ch = message;
   char *last_ch = message + (strlen(message) - 1);
   
   for ( ; first_ch <= last_ch; first_ch++, last_ch--) {
      char temp = *first_ch;
      *first_ch = *last_ch;
      *last_ch = temp;
   }
   
   printf("%s\n", message);
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
