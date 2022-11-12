/*
 * sorts an array of integers using Quicksort algorithm
 */
#include <stdio.h>
#include "../include/quicksort.h"

#define N 10

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   int a[N], i;

   printf("Enter %d numbers to be sorted: ", N);
   for (i = 0; i < N; i++)
      scanf("%d", &a[i]);

   quicksort(a, 0, N - 1);

   printf("In sorted order: ");
   for (i = 0; i < N; i++)
      printf("%d ", a[i]);
   printf("\n");

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int split(int a[], int low, int high) 
{
   int part_element = a[low];

   for (; ;) {
      while (low < high && part_element <= a[high])
         high--;
      if (low >= high) break;
      a[low++] = a[high];

      while (low < high && a[low] <= part_element)
         low++;
      if (low >= high) break;
      a[high--] = a[low];
   }

   a[high] = part_element;

   return high;
}
