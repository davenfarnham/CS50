/*
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
  if (values[n/2] == value)
    return true;
  else if (n <= 1)
    return false;
  else if (values[n/2] < value)
    return search(value, &values[n/2], (n - (n/2)));
  else if (values[n/2] > value)
    return search(value, values, (n - (n/2)));
  else
    return false;
}

/* shift values to the right. End is the first value you will overwrite,
 * while start is the leftmost value
 */
void shift(int values[], int start, int end)
{
  int temp = values[end];

  for (int i = end; i > start; i--)
  {
    values[i] = values[i-1];
  }
}

/**
 * Sorts array of n values. (Insertion sort)
 */
void sort(int values[], int n)
{
  for (int i = 1; i < n; i++)
  {
    for (int k = 0 ; k <= i; k++)
    {
      if(values[i] < values[k])
      {
        int temp = values[i];

        // values[] should be passed by reference
        shift(values, k, i);

        values[k] = temp;
        break;
      }
    }
  }
}
