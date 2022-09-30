/**
 *
 * The following table shows the daily flights from one city to another:
 *
 *    Departure time    Arrival time
 *    8:00 a.m.         10:16 a.m.
 *    9:43 a.m.         11:52 a.m.
 *    11:19 a.m.        1:31 p.m.
 *    12:47 p.m.        3:00 p.m.
 *    2:00 p.m.         4:08 p.m.
 *    3:45 p.m.         5:55 p.m.
 *    7:00 p.m.         9:20 p.m.
 *    9:45 p.m.         11:58 p.m.
 *
 * Write a program that asks user to enter a time
 * (expressed in hours and minutes, using the 24-hour clock). The program
 * then displays the departure and arrival times for the fight whose
 * departure time is closest to that entered by the user:
 *
 *    Enter a 24-hour time: 13:15
 *    Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
 *
 * Hint: Convert the input into a time expressed in minutes since midnight,
 * and compare it to the departure times, also expressed in minutes since midnight.
 * For example, 13:15 is 13 x 60 + 15 = 795 minutes since midnight, which is closer
 * to 12:47 p.m. (767 minutes since midnight) than to any of the other departure times.
 */

#include <stdio.h>

int main(void) 
{
   int hour, minutes, total_minutes;

   printf("Enter a 24-hour time: ");
   scanf("%d:%d", &hour, &minutes);

   total_minutes = hour * 60 + minutes;

   printf("Closest departure time is ");
   
   if (total_minutes > 1303)
      printf("9:45 p.m., arriving at 11:58 p.m\n");
   else if (total_minutes > 1140)
      printf("7:00 p.m., arriving at 9:20 p.m\n");
   else if (total_minutes > 945)
      printf("3:45 p.m., arriving at 5:55 p.m\n");
   else if (total_minutes > 840)
      printf("2:00 p.m., arriving at 4:08 p.m\n");
   else if (total_minutes > 767)
      printf("12:47 p.m., arriving at 3:00 p.m\n");
   else if (total_minutes > 679)
      printf("11:19 a.m., arriving at 1:31 p.m\n");
   else if (total_minutes > 583)
      printf("9:43 a.m., arriving at 11:52 a.m\n");
   else
      printf("8:00 a.m., arriving at 10:16 a.m\n");

   return 0;
}
