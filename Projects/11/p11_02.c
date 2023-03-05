/**
 *
 * Modify Programming Project 8 from Chapter 5 so that it includes the following function:
 *
 *    void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
 *
 * This function will find the flight whose departure time is closest to desired_time
 * (expressed in minutes since midnight). It will store the departure and arrival times
 * of this flight (also expressed in minutes since midnight) in the variables pointed to by
 * departure_time and arrival_time, respectively.
 *
 */
#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

/* external variable    */
bool found = false;

void find_closest_flight(int, int *, int *);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void)
{
   int hour, minutes, total_minutes;
   int departure_times[SIZE] = {1305, 1140, 945, 840, 767, 679, 583, 480};
   int arrival_times[SIZE] = {1438, 1280, 1075, 968, 900, 811, 712, 616};

   printf("Enter a 24-hour time: ");
   scanf("%d:%d", &hour, &minutes);

   total_minutes = hour * 60 + minutes;

   printf("Closest departure time is ");
   for (int i = 0; i < SIZE; i++) {
      find_closest_flight(total_minutes, &departure_times[i], &arrival_times[i]);

      if (found)
         break;
   }

   if (!found)
      printf("8:00 a.m., arriving at 10:16 a.m.\n");

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
   char indicator = (desired_time > 719) ? 'p' : 'a';
   int dep_hour = *departure_time / 60;
   int dep_minutes = *departure_time % 60;
   int arr_hour = *arrival_time / 60;
   int arr_minutes = *arrival_time % 60;

   if (indicator == 'p' && dep_hour > 12) dep_hour -= 12;
   if (indicator == 'p' && arr_hour > 12) arr_hour -= 12;

   if (dep_hour == 24) dep_hour = 0;
   if (arr_hour == 24) arr_hour = 0;

   if (desired_time > *departure_time) {
      printf("%d:%02d %c.m., arriving at %d:%02d %c.m.\n",
            dep_hour, dep_minutes, indicator,
            arr_hour, arr_minutes, indicator);

      found = true;
      return;
   }
}
