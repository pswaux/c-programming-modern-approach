/**
 *
 * Modify Programming Project 11 from Chapter 7 so that it includes the following function:
 * 
 *       void reverse_name(char *name);
 *
 * The function expects name to point to a string containing a first name followed by a 
 * last name. It modifies the string so that the last name comes first, followed by a comma, 
 * a space, the first initial, and a period. The orginal string may contain extra spaces 
 * before the first name, between the first and last names, and after the last name.
 *
 */
#include <stdio.h>
#include <ctype.h>

#define LENGTH 50

/* prototypes  */
void reverse_name(char *name);
int read_line(char str[], int n);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   char name[LENGTH];

   printf("Please enter your first and last name: ");
   read_line(name, LENGTH);

   reverse_name(name);

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void reverse_name(char *name)
{
   // find the index number of space character
   int space = 0;
   while (*(name + space++) != ' ');

   // name[space] indicates the first character of the last name
   printf("%s, %c.\n", (name + space), *name);
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
