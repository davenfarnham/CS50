/*
 *
 * Daven Farnham (2015)
 *
 * Selection Sort: O(n^2) Ω(n^2)
 *
 */

#include <stdio.h>
#include "sorts.h"

void selection (int* array, int size)
{
  for (int outer = 0; outer < size - 1; outer++)
  {
      // current min value
      int index = outer;

      for (int inner = outer + 1; inner < size; inner++)
      {
	  if (array[inner] < array[index])
	  {
	      index = inner;
	  }
      }
 
      swap(&array[index], &array[outer]);
  }
}
