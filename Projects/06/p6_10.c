/**
 *
 * Programming Project 9 in Chapter 5 asked you to write
 * a program that determines which of two dates comes earlier
 * on the calendar. Generalize the program so that the user may
 * enter any number of dates. The user will enter 0/0/0 to indicate
 * that no more dates will be entered:
 *
 *    Enter a data (mm/dd/yy): 3/6/8
 *    Enter a data (mm/dd/yy): 5/17/07
 *    Enter a data (mm/dd/yy): 6/3/07
 *    Enter a data (mm/dd/yy): 0/0/0
 *    5/17/07 is the earliest date
 *
 */
#include <stdio.h>

int main(void) 
{
   int day, month, year;
   int min_day = 32, min_month = 13, min_year = 99;

   printf("Enter a date (mm/dd/yy): ");
   while (scanf("%d/%d/%d", &month, &day, &year)) {
      if (month == 0 && day == 0 && year == 0) {
         printf("%02d/%02d/%02d is the earliest date\n", 
            min_month, min_day, min_year);
         break;
      }

      if ((year < min_year) || (year == min_year && month < min_month) ||
         (year == min_year && month == min_month && day < min_day)) {
            min_month = month;
            min_day = day;
            min_year = year;
      }
      printf("Enter a date (mm/dd/yy): ");
   }

   return 0;
}
