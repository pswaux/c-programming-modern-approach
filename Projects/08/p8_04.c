/**
 * 
 * Modify the reverse.c program of Section 1 to use the expression
 * (int) (sizeof (a) / sizeof (a[0)) (or a macro with this value)
 * for the array length.
 * 
 */
#include <stdio.h>

#define N (int) (sizeof(a) / sizeof(a[0]))

int main(void)
{
   int i, n;

   printf("How many numbers do you want to enter? ");
   scanf("%d", &n);

   printf("Enter %d numbers: ", n);
   int a[n];
   for (i = 0; i < N; i++)
      scanf("%d", &a[i]);

   printf("In reverse order:");
   for (i = N - 1; i >= 0; i--)
      printf(" %d", a[i]);
   printf("\n");

   return 0;
}
