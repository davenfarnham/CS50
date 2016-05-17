/*
 *
 * Daven Farnham (2015)
 *
 * Bubble Sort: O(n) Ω(n^2)
 *
 */

#include <stdio.h>
#include "sorts.h"

void bubble (int* array, int size)
{
    int swaps = 0;

    for (int h = size; h > 0; h--)
    {
	for (int i = 0; i < h - 1; i++)
	{
	    	if (array[i] > array[i + 1])
		{
		    swap(&array[i], &array[i + 1]);
	            swaps++;
		}
	}

	if (swaps == 0)
	  return;
    }
}
