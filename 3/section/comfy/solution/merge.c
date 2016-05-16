/*
 *
 * Daven Farnham (Fall 2015)
 *
 * Merge Sort: O(nlogn) Ω(nlogn). Divide and conquer
 * algorithm.
 *
 */

#define SIZE 30

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "helpers.h"

// prototypes
int* combine (int* left, int s1, int* right, int s2);
int* explode(int* array, int size);

int main(void)
{
	// malloc space on the heap
	int* array = malloc(sizeof(int) * SIZE);

	// seed the random number generator
	srand(time(NULL));

	// place random numbers into the array
	for (int i = 0; i < SIZE; i++)
	    *(array + i) = (rand() % 100);	
	
	// call function explode, which will act recursively to divide array
	int* temp = explode(array, SIZE);

	// print out sorted array
	print_array(temp, SIZE);

	// free array
	free(temp);
}

// pass in two arrays each with their size
int* combine (int* left, int s1, int* right, int s2)
{
    // values to index into left array, right array, and temp
    // array, respectively.
    int l = 0, r = 0, i = 0;

    // temp array to store combined left & right
    int* temp = malloc(sizeof(int) * (s1 + s2));

    // combine the arrays
    while (l < s1 && r < s2)
    {
	/* this notation uses pointer arithmetic. *(left + l) is 
	 * basically the same as left[l]. */
        if (*(left + l) < *(right + r))
	{
     	    *(temp + i) = *(left + l);
	     l++;
        }
	else if (*(left + l) > *(right + r))
	{
            *(temp + i) = *(right + r);
	    r++;
        }
        else
	{
            *(temp + i) = *(left + l);
     	    l++;
	}

	i++;
    }

    /* if you reach the end of one of the arrays (left or right)
     * copy the rest of the values from whichever array did not 
     * reach the end into temp. */
    if (l < s1)
        /* this function copies values into destination, from source, # of bytes.
	 * So to be explicit: memcpy(destination, source, # of bytes). */
        memcpy(temp + i, left + l, (s1 - l) * sizeof(int));        
    else
        memcpy(temp + i, right + r, (s2 - r) * sizeof(int));

    /* free the left and right arrays you started with (since now all the values
     * are in temp) so you don't get memory leaks. */
    free(left);
    free(right);

    // return pointer to new array
    return temp;        
}

int* explode(int* array, int size)
{
    // base case (size of 1)
    if (size == 1)
    {
	// malloc memory for array of size 1
	int* single = malloc(sizeof(int) * size);
        memcpy(single, array, sizeof(int));
	free (array);
	return single;
    }

    // find middle of array
    int mid = size / 2;
  
    // new array for the left half
    int* left = malloc(sizeof(int) * (mid));
    // copy values into the new array
    memcpy(left, array, mid * sizeof(int));

    // new array for the right half
    int* right = malloc(sizeof(int) * (size - mid));
    // copy values into the new array
    memcpy(right, array + mid, (size - mid) * sizeof(int));

    // free original array
    free (array);

    // call combine on a recursive call to explode
    return combine (explode(left, mid), mid, explode(right, (size - mid)), (size - mid));        	
}
