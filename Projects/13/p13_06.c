/**
 *
 * Improve the planet.c program of Section 13.7 by having it ignore case 
 * when comparing command-line arguments with strings in the planets array.
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

/* prototypes  */
int is_equal(const char *str1, const char *str2);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(int argc, char *argv[])
{
   char *planets[] = {
      "Mercury", "Venus", "Earth", "Mars", "Jupiter",
      "Saturn", "Uranus", "Neptune", "Pluto"
   };
   int i, j;

   for (i = 1; i < argc; i++) {
      for (j = 0; j < NUM_PLANETS; j++) {
         if (is_equal(argv[i], planets[j])) {
            printf("%s is planet %d\n", argv[i], j + 1);
            break;
         }
      }
      if (j == NUM_PLANETS)
         printf("%s is not a planet\n", argv[i]);
   }

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int is_equal(const char *str1, const char *str2)
{
   while (tolower(*str1++) == tolower(*str2++)) {
      if (*str1 == '\0' && *str2 == '\0')
         return 1;
   }

   return 0;
}
