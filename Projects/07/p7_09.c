/**
 *
 * Write a program that asks the user for a 12-hour time, 
 * then displays the time in 24-hour form:
 * 
 *    Enter a 12-hour time: 9:11 PM
 *    Equivalent 24-hour time: 21:11
 *
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
   int hour, minutes;
   char indicator;

   printf("Enter a 12-hour time: ");
   scanf("%d:%d %c", &hour, &minutes, &indicator);

   // convert to 24-hour time
   if (toupper(indicator) == 'P')
      hour += 12;

   if (hour == 24) hour = 0;
   
   printf("Equivalent 24-hour time: %d:%d\n", hour, minutes);   
   
   return 0;
}
