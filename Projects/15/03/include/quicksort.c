#include "quicksort.h"

void quicksort(int a[], int low, int high) {
   int middle;

   if (low >= high) return;

   middle = split(a, low, high);
   quicksort(a, low, middle - 1);
   quicksort(a, middle + 1, high);
}
