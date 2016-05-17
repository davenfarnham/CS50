/*
 *
 * Daven Farnham (2015)
 *
 * Insertion Sort: O(n) Ω(n^2). Insert an element in its
 * correct position in the array.
 *
 */

#include "sorts.h"

void place (int* array, int position, int move);

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
	    place(array, sorted + 1, unsorted);
	    break;
	  }

	  if(!sorted)
            place(array, 0, unsorted);
	}
    }
}

// shift array to the right
void place (int* array, int sorted, int unsorted)
{
	int temp = array[unsorted];

	for (int i = unsorted; i > sorted; i--)
	{
		array[i] = array[i-1];
	}

	array[sorted] = temp;
}
