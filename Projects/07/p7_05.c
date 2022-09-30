/**
 *
 * In the SCRABBLE Crossword Game, players form words using small tiles,
 * each containing a letter and a face value. The face value varies from
 * one letter to another, based on the letter’s rarity.
 * (Here are the face values: 1: AEILNORSTU. 2: DG, 3: BCMP, 4: FHVWY,
 * 5: K, 8: JX, 10: QZ.)
 * Write a program that computes the value of a word by summing the values
 * of its letters:
 *
 *    Enter a word: pitfall
 *    Scrabble value: 12
 *
 * Your program should allow any mixture of lower-case and upper-case letters
 * in the word. Hint: Use the toupper library function.
 *
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
   char letter;
   int sum = 0;

   printf("Enter a word: ");
   while ((letter = getchar()) != '\n') {
      switch (toupper(letter)) {
         case 'A': case 'E': case 'I': case 'L':
         case 'N': case 'O': case 'R': case 'S':
         case 'T': case 'U':
            sum += 1; break;
         case 'D': case 'G':
            sum += 2; break;
         case 'B': case 'C': case 'M': case 'P':
            sum += 3; break;
         case 'F': case 'H': case 'V': case 'W':
         case 'Y':
            sum += 4; break;
         case 'K':
            sum += 5; break;
         case 'J': case 'X':
            sum += 8; break;
         case 'Q': case 'Z':
            sum += 10; break;
      }
   }

   printf("Scrabble value: %d\n", sum);
   return 0;
}
