/*
 * A rough program to approximate the runtimes of different sorting algorithms (bubble, insertion,
 * selection, and merge). Shows how for smaller lists, insertion might run fastest, but for large
 * unsorted lists merge will almost always outperform the others.
 *
 * By Daven Farnham (2014)
 */

#include "helpers.h"
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <ctype.h>
#include <stdio.h>

#define ALOT 60000
#define LIMIT 65536
#define _XOPEN_SOURCE

#undef calculate
#undef getrusage

// calculate time
double calculate(const struct rusage* b, const struct rusage* a);

int main(void)
{
    // initialize a big array
    int big_array[ALOT];
    int big_array2[ALOT];
    int big_array3[ALOT];
    int big_array4[ALOT];

    // seed random
    srand((long int) time(NULL));

    // insert random ints into array
    for(int i = 0; i < ALOT; i++)
    {
        int insert = (int) (rand() * LIMIT);

        big_array[i] = insert;
        big_array2[i] = insert;
        big_array3[i] = insert;
        big_array4[i] = insert;
    }

    // with a size
    int size = ALOT;

    // struct for time usage
    struct rusage before, after;

    // get time of bubble sort
    getrusage(RUSAGE_SELF, &before);
    int* arr_ptr = bubble_sort(big_array, size);
    getrusage(RUSAGE_SELF, &after);

    // do nothing with ptr
    (void) arr_ptr;

    // calculate time
    double time = calculate(&before, &after);

    // print out time
    printf("Bubble Sort runs in: %f Seconds\n", time);

    // get time of selection sort
    getrusage(RUSAGE_SELF, &before);
    int* arr_ptr2 = selection_sort(big_array2, size);
    getrusage(RUSAGE_SELF, &after);

    // do nothing with ptr
    (void) arr_ptr2;

    // calculate time
    double time2 = calculate(&before, &after);

    // print out time
    printf("Selection Sort runs in: %f Seconds\n", time2);

    // get time of insertion sort
    getrusage(RUSAGE_SELF, &before);
    int* arr_ptr3 = insertion_sort(big_array3, size);
    getrusage(RUSAGE_SELF, &after);

    // do nothing with ptr
    (void) arr_ptr3;

    // calculate time
    double time3 = calculate(&before, &after);

    // print out time
    printf("Insertion Sort runs in: %f Seconds\n", time3);

    // get time of merge sort
    getrusage(RUSAGE_SELF, &before);
    int* arr_ptr4 = sort(big_array4, size);
    getrusage(RUSAGE_SELF, &after);

    free(arr_ptr4);

    // calculate time
    double time4 = calculate(&before, &after);

    // print out time
    printf("Merge Sort runs in: %f Seconds\n", time4);
}

/**
 * Returns number of seconds between b and a. Borrowed from one of CS50's psets (I think it
 * might be speller)
 */
double calculate(const struct rusage* b, const struct rusage* a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                 (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                 (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}
