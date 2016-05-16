/*
 *
 * Daven Farnham (2015)
 *
 * Main function to run sorting functions.
 *
 */

#include <stdio.h>
#include "sorts.h"
#include <stdlib.h>

#define ARRAYSIZE 25

int main (void)
{

        int array[ARRAYSIZE] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 10, 11, 12, 67, 51, 99, 44, 32, 27, 81, 76, 14, 100, 673, 144, 500};

	bubble(array, ARRAYSIZE);

        printf("Bubble Sort: ");

        for (int i = 0; i < ARRAYSIZE; i++)
        {
                printf("%i ", array[i]);
        }

        printf("\n");

        int array1[ARRAYSIZE] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 10, 11, 12, 67, 51, 99, 44, 32, 27, 81, 76, 14, 100, 673, 144, 500};

	selection(array1, ARRAYSIZE);

        printf("Selection Sort: ");

        for (int i = 0; i < ARRAYSIZE; i++)
        {
                printf("%i ", array1[i]);
        }

        printf("\n");

        int array2[ARRAYSIZE] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 10, 11, 12, 67, 51, 99, 44, 32, 27, 81, 76, 14, 100, 673, 144, 500};

	insertion(array2, ARRAYSIZE);

        printf("Insertion Sort: ");

        for (int i = 0; i < ARRAYSIZE; i++)
        {
                printf("%i ", array2[i]);
        }

        printf("\n");

}
