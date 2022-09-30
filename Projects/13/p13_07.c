/**
 *
 * Modify Programming Project 11 from Chapter 5 so that it uses arrays containing pointers to
 * strings instead of switch statements. For example, instead of using a switch statement
 * to print the word for the first digit, use the digit as an index into an array that contains 
 * the strings "twenty", "thirty". and so forth.
 *
 */
#include <stdio.h>

int main(void)
{
   int number;
   char *ones[] = {
      "one", "two", "three", "four", "five", "six",
      "seven", "eight", "nine"
   };

   char *tens[] = {
      "twenty", "thirty", "fourty", "fifty", "sixty",
      "seventy", "eighty", "ninety"
   };

   printf("Enter a two-digit number: ");
   scanf("%d", &number);

   printf("You entered the number ");
   if (number < 20) {
      switch (number - 10) {
         case 0 : printf("ten.\n"); break;
         case 1 : printf("eleven.\n"); break;
         case 2 : printf("twelve.\n"); break;
         case 3 : printf("thirteen.\n"); break;
         case 4 : printf("fourteen.\n"); break;
         case 5 : printf("fifteen.\n"); break;
         case 6 : printf("sixteen.\n"); break;
         case 7 : printf("seventeen.\n"); break;
         case 8 : printf("eighteen.\n"); break;
         case 9 : printf("nineteen.\n"); break;
      }
   } else if (number % 10 == 0) {
      printf("%s\n", tens[number/10 - 2]);
   } else {
      printf("%s-%s\n", tens[number/10 - 2], ones[number%10 - 1]);
   }
   
   return 0;
}
