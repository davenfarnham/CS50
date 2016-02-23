/*
 *
 * By Daven Farnham (Fall 2015) 
 *
 * A short program to try and illustrate that a multidimensional array is basically
 * the same as a normal array. Declare a1 as a multidimensional array then index into
 * it using (1) a2 which is a pointer to a1 and (2) pointer arithmetic on a1. 
 * 
 * Multidimensional array notation is really for us to make things more readable. In 
 * actuality all arrays are simply laid out in memory as contiguous blocks of memory.
 *
 */

#include <stdio.h>

int main (void)
{
    // a multidimensional array
    int a1[2][5];

    // pointer to a1; basically just another array
    int* a2 = (int*) a1;

    // fill up a1
    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 5; k++)
	    a1[i][k] = ((i * 5) + k);

    // index into a2 like a non-multidimensional array
    printf ("%i\n", a2[9]);

    // treat a1 like a block of memory using pointer arithmetic
    printf ("%i\n", *((int*) a1 + 9));
}
