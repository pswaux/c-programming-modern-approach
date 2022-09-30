/**
 * 
 * Modify the program of Programming Project 2 so that it prompts the user
 * to enter the radius of the sphere.
 *
 */

#include <stdio.h>

int main(void) 
{
	float radius = 0.0f;

	printf("Please enter the radius: ");
	scanf("%f", &radius);
	
	float volume = (4.0f / 3.0f) * 3.1415f * (radius * radius * radius);

	printf("The volume of the sphere: %.2f\n", volume);

	return 0;
}
