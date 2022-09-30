/**
 * 
 * One of the oldest known encryption techniques is the Caesar cipher,
 * attributed to Julius Caesar. It involves replacing each letter in a
 * message with another letter that is a fixed number of positions later
 * in the alphabet. (If the replacement would go past the letter Z,
 * the cipher “wraps around” to the beginning of the alphabet. For example,
 * if each letter is replaced by the letter two positions after it,
 * then Y would be replaced by A, and Z would be replaced by B).
 *
 * Write a program that encrypts a message using a Caesar cipher. The user will
 * enter the message to be encrypted and the shift amount (the number of positions
 * by which letters should be shifted):
 *
 *    Enter a message to be encrypted: Go ahead, make my day.
 *    Enter shift amount (1-25): 3
 *    Encrypted message: Jr dkhdg, pdnh pb gdb.
 *
 * Notice that the program can decrypt a message if the user enters
 * 26 minus the original key:
 *
 *    Enter a message to be encrypted: Jr dkhdg, pdnh pb gdb.
 *    Enter shift amount (1-25): 23
 *    Encrypted message: Go ahead, make my day.
 *
 * You may assume that the message does not exceed 80 characters. Characters
 * other than letters should be left unchanged. Lower-case letters remain
 * lower-case when encrypted, and upper-case letters remain upper-case.
 *
 * Hint: To handle the wrap-around problem, use the expression
 * ((ch - 'A') +n) % 26 + 'A' to calculate the encrypted version of an upper-case
 * letter, where ch stores the letter and n stores the shift amount.
 * (You'll need a similar expression for lower-case letters.)
 * 
 */
#include <stdio.h>


#define SIZE 80

int main(void)
{
   char message[SIZE];
   int shift;
   char ch;

   printf("Enter message to be encrypted: ");
   for (int i = 0; i < SIZE; i++) {
      ch = getchar();
      message[i] = ch;

      if (ch == '\n') break;
   }

   printf("Enter shift amount: ");
   scanf("%d", &shift);

   printf("Encrypted message: ");
   for (int i = 0; i < SIZE; i++) {
      if (message[i] >= 'A' && message[i] <= 'Z')
         putchar(((message[i] - 'A') + shift) % 26 + 'A');
      else if (message[i] >= 'a' && message[i] <= 'z')
         putchar(((message[i] - 'a') + shift) % 26 + 'a');
      else
         putchar(message[i]);

      if (message[i] == '\n') break;
   }

   printf("\n");
   return 0;
}
