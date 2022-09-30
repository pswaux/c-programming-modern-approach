/**
 *
 * Modify Programming Project 8 from Chapter 5 so that the user
 * enters a time using the 12-hour clock. The input will have the
 * form hours : minutes followed by either A, P, AM, or PM 
 * (either lower-case or upper-case). White space is allowed
 * (but not required) between the numerical time and the AM/PM indicator.
 * Examples of valid input:
 * 
 *    1:15P
 *    1:15PM
 *    1:15p
 *    1:15pm
 *    1:15 P
 *    1:15 PM
 * 
 * You may assume that the input has one of these forms;
 * there is no need to test for errors.
 *
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
   int hour, minutes, total_minutes;
   char indicator;

   printf("Enter a 12-hour time: ");
   scanf("%d:%d %c", &hour, &minutes, &indicator);

   // convert to 24-hour time
   if (toupper(indicator) == 'P' && hour != 12)
      hour += 12;

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
