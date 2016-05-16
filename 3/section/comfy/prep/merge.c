/*
 *
 * Pass in from main an array, left = 0 and s1 = right - left, right = mid and s2
 * = total length - mid.
 *
 * merge(explode(left, s1), explode(right, s2));
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// pass in two arrays each with their size
int* combine (int* left, int s1, int* right, int s2)
{
    int l = 0;
    int r = 0;
    int i = 0;

    // temp array
    int* temp = malloc(sizeof(int) * (s1 + s2));

    while (l < s1 && r < s2)
    {

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
	    r++;
	}

	i++;
    }

    if (l < s1)
        memcpy(temp + i, left + l, (s1 - l) * sizeof(int));        
    else
        memcpy(temp + i, right + r, (s2 - r) * sizeof(int));

    free(left);
    free(right);

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

    free (array);

    return combine (explode(left, mid), mid, explode(right, (size - mid)), (size - mid));        	
}

