/*
 *
 * By Daven Farnham (Fall 2015)
 *
 * Solution to problem. Students should (1) check the # of cmd-line arguments, (2) convert to an integer,
 * (3) place user's input into array, (4) sum array.
 * 
 * This is a good exercise working with cmd-line arguments and arrays.
 *
 */

#include <stdio.h>
#include <stdlib.h>

// header file
int sum (int* array, int count);

int main (int argc, char* argv[])
{
  // check # of cmd line arguments
  if (argc != 2)
  {
      printf ("Please give me a number of terms to sum.\n");
      return 1;
  }

  // convert string to int
  int size = atoi(argv[1]);

  // compiler allows for variable length arrays
  int array[size];

  // prompt user for input; store in array
  for (int i = 0; i < size; i++)
  {
    int k;

    // scanf instead of GetInt()
    scanf("%i", &k);

    array[i] = k;
  }

  // print out sum of array
  printf ("You gave me a total of %i terms equaling %i.\n", size, sum(array, size));
}

// sum up the entries of an array
int sum (int* array, int count)
{
  int sum = 0;

  for (int i = 0; i < count; i++)
      sum = sum + array[i];

  return sum;
}
