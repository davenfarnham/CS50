/*
 *
 * Daven Farnham (Fall 2015)
 *
 * Insertion Sort: O(n) Ω(n^2). Insert an element in its 
 * correct position in the array.
 *
 */

#define SIZE 15
#include "helpers.h"

// prototypes
void insertion(int* array, int size);
void shift (int* array, int position, int move);

// simple main function to test
int main(void)
{
    int array[SIZE] = {-10, -4, 0, 8, -24, 3, 2, 1, 40, 25, -2, 9, 144, -98, 7};

    insertion(array, SIZE);

    // helper function to print out array (in helpers.c)
    print_array (array, SIZE);
}

// insertion sort
void insertion(int* array, int size)
{
    // trivial case
    if(size == 1)
        return;

    for (int unsorted = 1; unsorted < size; unsorted++)
    {
        for (int sorted = unsorted - 1; sorted >= 0; sorted--)
	{
	  if (array[unsorted] > array[sorted])
	  {
	    shift(array, sorted + 1, unsorted);
	    break;
	  }

	  if(!sorted)
            shift(array, 0, unsorted);
	}
    }
}

// shift array to the right from sorted to unsorted
void shift (int* array, int sorted, int unsorted)
{
	int temp = array[unsorted];
	
	for (int i = unsorted; i > sorted; i--)
	{
		array[i] = array[i-1]; 
	}

	array[sorted] = temp;
}
