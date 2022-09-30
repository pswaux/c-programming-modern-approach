/**
 * 
 * The prototypical Internet newbie is a fellow named BIFF,
 * who has a unique way of writing messages. Here's a typical
 * BIFF communiqué:
 *
 *    H3Y DUD3, C 15 R1LLY C00L!!!!!!
 *
 * Write a “BIFF filter” that reads a message entered by the user
 * and translates it into BIFF-speak:
 *
 *    Enter message: Hey dude, C is rilly cool
 *    In BIFF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!
 *
 * Your program should convert the message to upper-case letters,
 * substitute digits for certain letters (A —> 4, B -> 8, E ->3,
 * I -> 1,  O -> 0, S —> 5), and then append 10 or so exclamation marks.
 *
 * Hint: Store the original message in an array of characters,
 * then go back through the array, translating and printing characters
 * one by one.
 * 
 */
#include <stdio.h>
#include <ctype.h>

#define SIZE 50

int main(void)
{
   char message[SIZE];

   /* initialize the array */
   for (int i = 0; i < SIZE; i++)
      message[i] = '!';

   printf("Enter message: ");
   for (int i = 0; i < SIZE; i++) {
      message[i] = getchar();

      if (message[i] == '\n') {  // if it's the end of message
         message[i] = '!';       // replace the last character with '!'
         break;
      }
   }

   printf("In BIFF-speak: ");
   for (int i = 0; i < SIZE ; i++) {
      switch (toupper(message[i])) {
         case 'A': printf("4"); break;
         case 'B': printf("8"); break;
         case 'E': printf("3"); break;
         case 'I': printf("1"); break;
         case 'O': printf("0"); break;
         case 'S': printf("5"); break;
         default: printf("%c", toupper(message[i]));
      }
   }

   printf("\n");

   return 0;
}
