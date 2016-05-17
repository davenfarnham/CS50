/*
 *
 * Merge Sort: O(nlogn) Ω(nlogn). Divide and conquer
 * algorithm.
 *
 */

#define SIZE 20

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "helpers.h"

// so you don't print too far past the end of array
int duplicates = 0;

// pass in two arrays each with their size
int* combine (int* left, int s1, int* right, int s2)
{
    int l = 0;
    int r = 0;
    // index into temp array
    int i = 0;

    // temp array
    int* temp = malloc(sizeof(int) * (s1 + s2));

    while (l < s1 && r < s2)
    {
	    // TODO
    }

    // place the rest of values into the temp array
    if (l < s1)
        memcpy(temp + i, left + l, (s1 - l) * sizeof(int));
    else
        memcpy(temp + i, right + r, (s2 - r) * sizeof(int));

    free(left);
    free(right);

    return temp;
}

// recursively subdivide array
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

    free (array);

    return combine (explode(left, mid), mid, explode(right, (size - mid)), (size - mid));
}

int main(void)
{
	int* array = malloc(sizeof(int) * SIZE);

	// randomize inputs to array
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
	    *(array + i) = (rand() % 100);

//	print_array (array, SIZE);

	int* temp = explode(array, SIZE);

	// print out sorted array
	print_array(temp, SIZE - duplicates);
}
