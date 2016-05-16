/*
 * Another test program for merge sort. Use it to read in numbers via
 * ./merge_test-2 < input_file.txt
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include "helpers.c"
#include <cs50.h>

int main(void)
{
    int* array = malloc(sizeof(int) * 10002);

    for(int i = 0; i < 10002; i++)
    {
        *(array + i) = GetInt();
    }

    // sort via merge sort
    int* new_array = sort(array, 10002);

    // print out the results
    for(int i = 0; i < 10002; i++)
        printf("%i ", *(new_array + i));

    free(new_array);

    printf("\n");
}
