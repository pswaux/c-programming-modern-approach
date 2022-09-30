/**
 *
 * Write a program that prompts the user to enter two dates and
 * then indicates which date comes earlier on the calendar:
 *
 *    Enter first date (mm/dd/yy): 3/6/08
 *    Enter second date (mm/dd/yy): 5/17/07
 *    5/17/07 is earlier than 3/6/08
 *
 */

#include <stdio.h>

int main(void) 
{
   int day1, day2, month1, month2, year1, year2;

   printf("Enter first date (mm/dd/yy): ");
   scanf("%d/%d/%d", &month1, &day1, &year1);

   printf("Enter second date (mm/dd/yy): ");
   scanf("%d/%d/%d", &month2, &day2, &year2);

   if ((year1 < year2) || (year1 == year2 && month1 < month2) ||
         (year1 == year2 && month1 == month2 && day1 < day2))
      printf("%d/%d/%02d is earlier than %d/%d/%02d\n",
         month1, day1, year1, month2, day2, year2);
   else
      printf("%d/%d/%02d is earlier than %d/%d/%02d\n",
         month2, day2, year2, month1, day1, year1);

   return 0;
}
