/**
 *
 * Modify Programming Project 15 from Chapter & so that it includes the 
 * following function:
 *
 *       void encrypt(char *message, int shift);
 *
 * The function expects message to point to a string containing the message 
 * to be encrypted; shift represents the amount by which each letter in the 
 * message is to be shifted.
 *
 */
#include <stdio.h>
#include <string.h>

#define SIZE 80

/* prototypes */
void encrypt(char *message, int shift);
int read_line(char str[], int n);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   char message[SIZE];
   int shift;

   printf("Enter message to be encrypted: ");
   read_line(message, SIZE);

   printf("Enter shift amount: ");
   scanf("%d", &shift);

   printf("Encrypted message: ");
   encrypt(message, shift);

   printf("\n");
   return 0;
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

void encrypt(char *message, int shift)
{
   for (int i = 0; i < strlen(message); i++) {
      if (*(message + i) >= 'A' && *(message + i) <= 'Z')
         putchar(((*(message + i) - 'A') + shift) % 26 + 'A');
      else if (*(message + i) >= 'a' && *(message + i) <= 'z')
         putchar(((*(message + i) - 'a') + shift) % 26 + 'a');
      else
         putchar(*(message + i));

      if (*(message + i) == '\n') break;
   }
}
