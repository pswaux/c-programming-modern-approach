/**
 *
 * Write a program that prompts the user to enter a number n
 * then prints all even squares between 1 and n. For example,
 * if the user enters 100, the program should print the following:
 *
 *    4
 *    16
 *    36
 *    64
 *    100
 *
 */
#include <stdio.h>

int main(void) 
{
   int number;

   printf("Enter a number: ");
   scanf("%d", &number);

   for (int i = 2; i * i <= number; i += 2)
      printf("\t%d\n", i * i);

   return 0;
}
