/**
 * 
 * Modify Programming Project 8 from Chapter 5 so that the departure times
 * are stored in an array and the arrival times are stored in a second array.
 * (The times are integers, representing the number of minutes since midnight.)
 * The program will use a loop to search the array of departure times for the one
 * closest to the time entered by the user.
 * 
 */
#include <stdio.h>

#define SIZE 8

int main(void)
{
   int departure_times[SIZE] = { 480, 583, 679, 767, 840, 945, 1140, 1303 };
   int arrival_times[SIZE] = { 616, 712, 811, 900, 968, 1075, 1280, 1438 };
   int hour, minutes, total_minutes;
   int dep_hour, dep_min, arr_hour, arr_min;

   printf("Enter a 24-hour time: ");
   scanf("%d:%d", &hour, &minutes);

   total_minutes = hour * 60 + minutes;

   printf("Closest departure time is ");

   for (int i = SIZE - 1; i >= 0; i--) {
      if (total_minutes > departure_times[i]) {
         dep_hour = departure_times[i] / 60;
         dep_min = departure_times[i] % 60;
         arr_hour = arrival_times[i] / 60;
         arr_min = arrival_times[i] % 60;

         if (dep_hour > 12 && departure_times[i] > 719)
            dep_hour -= 12;

         if (arr_hour > 12 && arrival_times[i] > 719)
            arr_hour -= 12;

         printf("%d:%02d %c.m., ", dep_hour, dep_min, (departure_times[i] > 719) ? 'p' : 'a');
         printf("%d:%02d %c.m. ", arr_hour, arr_min, (arrival_times[i] > 719) ? 'p' : 'a');

         break;
      } else if (total_minutes <= departure_times[0]) {
         printf("%d:%02d %c.m., ", departure_times[0] / 60, departure_times[0] % 60, 'a');
         printf("%d:%02d %c.m. ", arrival_times[0] / 60, arrival_times[0] % 60, 'a');

         break;
      }
   }

   printf("\n");
   return 0;
}
