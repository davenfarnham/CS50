/*
 * show different ways to initialize arrays, as well as potential issues referencing memory
 * beyond the bounds of an array
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    // one way to initialize an array!
    int array1[5];
    array1[0] = 0;
    array1[1] = 1; // ...

    int array2[] = {0,1};

    int array3[5] = {0,1};

    // there are just garbarge values for array[2], array[3], & array[4]
    printf("array1 is: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%i ", array1[i]);
    }
    printf("\n");

    // why are there 0, 1, 0, 1??
    printf("array2 is: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%i ", array2[i]); // it's printing part of array3 that's in memory;
                                  // you are accessing memory you really shouldn't be
    }
    printf("\n");

    printf("array3 is: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%i ", array3[i]);
    }
    printf("\n");
}
