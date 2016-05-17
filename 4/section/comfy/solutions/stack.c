/*
 * Daven Farnham (Fall 2015)
 *
 * A simple example to show how the stack grows in size. In the Makefile,
 * I pass in the flag -w to compile without warnings. I then access a2 16
 * bytes from its end to effectively override the values in the previous
 * array a1.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main(void)
{
	int a1[] = {1, 2, 3, 4, 5}; // size of 20 bytes

	int a2[] = {6, 7, 8, 9, 10}; // size of 20 bytes

	int a3[] = {11, 12, 13, 14, 15, 16, 17, 18}; // size of 32 bytes


	printf("a1 starts at: %p\n", a1); // print out pointer locations of both arrays
	printf("a2 starts at: %p\n", a2);
	printf("a3 starts at: %p\n", a3); // there should be no padding between this and a2

	// there is a total of 32 bytes separating these two arrays (20 bytes + extra padding )
	a2[8] = 11;
	print_array(a1, 5);
}
