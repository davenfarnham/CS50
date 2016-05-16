/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
	// Set values for the top and the bottom of the search
	int lower = 0;
	int upper = n-1;

	// Binary search
	while(lower <= upper)
	{
		int middle = (upper+lower)/2;

		if(values[middle] == value)
			return true;
		else if(values[middle] < value)
			lower = middle + 1;
		else if(values[middle] > value)
			upper = middle - 1;
	}

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
	// Bubble
	for(int k = 0; k < n-1; k++)
	{
	    // optimization
		int swaps = 0;

		for(int i = 0; i < n-1; i++)
		{

			if(values[i] > values[i+1])
			{
				int temp = values[i];
				values[i] = values[i+1];
				values[i+1] = temp;

				swaps++;
			}
		}

		if(swaps == 0)
			break;
	}

    return;
}
