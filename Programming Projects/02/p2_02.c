/**
 * 
 * Write a program that computes the volume of a sphere with a 10-meter radius
 * using the formula v = 4/3πr³. Write the fraction 4/3 as 4.0f/3.0f.
 * (Try writing it as 4/3. What happens?) 
 * Hint: C doesn’t have an exponentiation operator, so you'll need to multiply r
 * by itself twice to compute r³.
 *
 */

#include <stdio.h>

int main(void)
{
	float radius = 10.0f;
	float volume = (4.0f / 3.0f) * 3.1415f * (radius * radius * radius);

	printf("The volume of the sphere with a 10-meter radius: %.3f\n", volume);

	return 0;
}
