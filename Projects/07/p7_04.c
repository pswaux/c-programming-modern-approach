/**
 *
 * Write a program that translates an alphabetic phone
 * number into numeric form:
 *
 *    Enter phone number: CALLATT
 *    2255288
 *
 * (In case you don't have a telephone nearby, here are
 * the letters on the keys: 2=ABC, 3=DEF, 4=GHI. 5=JKL,
 * 6=MNO, 7=PRS, 8=TUV, 9=WXY.) If the original phone number
 * contains nonalphabetic characters (digits or punctuation,
 * for example), leave them unchanged:
 *
 *    Enter phone number: 1-800-COL-LECT
 *    1-800-265-5328
 *
 * You may assume that any letters entered by the user are upper case.
 *
 */
#include <stdio.h>

int main(void)
{
   char ch;

   printf("Enter phone number: ");

   while ((ch = getchar()) != '\n') {
      switch (ch) {
         case 'A': case 'B': case 'C':
            putchar('2'); break;
         case 'D': case 'E': case 'F':
            putchar('3'); break;
         case 'G': case 'H': case 'I':
            putchar('4'); break;
         case 'J': case 'K': case 'L':
            putchar('5'); break;
         case 'M': case 'N': case 'O':
            putchar('6'); break;
         case 'P': case 'R': case 'S':
            putchar('7'); break;
         case 'T': case 'U': case 'V':
            putchar('8'); break;
         case 'W': case 'X': case 'Y': case 'Z':
            putchar('9'); break;
         default:
            putchar(ch);
      }
   }
   putchar('\n');
}
