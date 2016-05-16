/*
 * Use in conjunction with "./tests_insert" to check a sorted list.
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

    int* ptr = sort(array, ALOT);

    for(int i = 0; i < ALOT; i++)
    {
        printf("%i\n", *(ptr + i));
    }
}
