/**
 *
 * Write a program that asks the user for a 24-hour time, 
 * then displays the time in 12-hour form:
 *
 *    Enter a 24-hour time: 21:11
 *    Equivalent 12-hour time: 9:11 PM
 *
 * Be careful not to display 12:00 as 0:00.
 *
 */

#include <stdio.h>

int main(void)
{
	int hour, minute;

   printf("Enter a 24-hour time: ");
   scanf("%d:%d", &hour, &minute);

   int total_minutes = hour * 60 + minute;

   if (total_minutes >= 0 && total_minutes <= 59)                       // 00:00(0 minutes) - 00:59(59 minutes)
      printf("Equivalent 12-hour time: %d:%02d AM\n", hour+12, minute); // add 12 hour and AM
   else if (total_minutes >= 60 && total_minutes <= 719)                // 01:00(60 minutes) - 11:59(719 minutes)
      printf("Equivalent 12-hour time: %d:%02d AM\n", hour, minute);    // just add AM
   else if (total_minutes >= 720 && total_minutes <= 779)               // 12:00 - 12:59
      printf("Equivalent 12-hour time: %d:%02d PM\n", hour, minute);    // just add PM
   else if (total_minutes >= 780 && total_minutes <= 1439)              // 13:00 - 23:59
      printf("Equivalent 12-hour time: %d:%02d PM\n", hour-12, minute); // subtract 12 hour and PM

	return 0;
}
