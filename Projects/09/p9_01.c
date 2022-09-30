/**
 *
 * Write a program that asks the user to enter a series of integers
 * (which it stores in an array), then sorts the integers by calling
 * the function selection_sort. When given an array with n elements,
 * selection _sort must do the following:
 *
 *    1. Search the array to find the largest element, then move it to
 *       the last position in the array
 *    2. Call itself recursively to sort the first n — 1 elements of the array.
 *
 */
#include <stdio.h>

#define SIZE 5

/* function prototypes  */
void selection_sort(int a[], int size);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   int numbers[SIZE];

   printf("Please enter %d numbers: ", SIZE);
   for (int i = 0; i < SIZE; i++)
      scanf("%d", &numbers[i]);

   selection_sort(numbers, SIZE);

   for (int i = 0; i < SIZE; i++)
      printf("%3d", numbers[i]);

   printf("\n");
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void selection_sort(int arr[], int size)
{
   int max = 0;
   int found = 0;  // max number has found at this index
   int swap;

   if (size == 0) return;

   // find the max
   for (int i = 0; i < size; i++)
      if (arr[i] > max) {
         max = arr[i];
         found = i;
      }

   // swap the number that's at the last index with max number
   swap = arr[size - 1];
   arr[size - 1] = max;
   arr[found] = swap;

   selection_sort(arr, size - 1);
}
