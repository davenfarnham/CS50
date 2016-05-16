/*
 * Use to double check merge sort. Run: "./test_merge-1 > numbers.txt" to get a large list of
 * numbers, then feed this into the program: "./tests_insert < numbers.txt > sorted.txt".
 * You can then run diff on "sorted.txt" and whatever the output is from "./tests_merge" to
 * check to make sure they're the same.
 *
 * By Daven Farnham (2014)
 */

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>
#include <stdio.h>
#include "helpers.c"
#include <cs50.h>

#define ALOT 10000
#define LIMIT 65536

int main(void)
{
    int array[ALOT];

    for(int k = 0; k < ALOT; k++)
    {
        array[k] = GetInt();
    }

    int* ptr = insertion_sort(array, ALOT);

    for(int i = 0; i < ALOT; i++)
    {
        printf("%i\n", *(ptr + i));
    }
}
