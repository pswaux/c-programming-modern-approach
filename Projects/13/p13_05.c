/**
 *
 * Write a program named sum.c that adds up its command-line arguments, which are
 * assumed to be integers. Running the program by typing
 *    
 *    sum 8 24 62
 *    should produce the following output:
 *    Total: 94 
 *
 * Hint: Use the atoi function to convert each command-line argument from 
 * string form to integer form.
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int sum = 0;

   if (argc == 1) {
      printf("Usage: sum int1 int2 ...\n");
      exit(EXIT_FAILURE);
   }

   for (int i = 1; i < argc; i++)
      sum += atoi(argv[i]);

   printf("Total: %d\n", sum);
   return 0;
}
