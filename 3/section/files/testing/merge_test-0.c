/*
 * Test program for merge sort
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include "helpers.c"
#include <cs50.h>

int main(void)
{
    // malloc a new array on the heap
    int* array = malloc(sizeof(int) * 10);

    // create another array on the stack
    int array1[] = {1, 2, 3, 12, 11, 10, 2, 4, 5, 1};

    // copy values from stack onto heap array
    for(int i = 0; i < 10; i++)
    {
        *(array + i) = array1[i];
    }

    // 'sort' is merge sort. sort the above array (merge expects a pointer)
    int* new_array = sort(array, 10);

    // print out the new, sorted array
    for(int i = 0; i < 10; i++)
        printf("%i ", *(new_array + i));

    // clear up allocated memory
    free(new_array);

    printf("\n");
}
