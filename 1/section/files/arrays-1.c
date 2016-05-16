/*
 * arrays-1.c: Go over the initialization of arrays as well as touch on how data
 * is stored in memory.
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

    // another way
    int array2[] = {0,1};

    // and yet another way!
    int array3[5] = {0,1};

    // there are just garbarge values for array1[2], array1[3], & array1[4]
    printf("array1 is: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%i ", array1[i]);
    }
    printf("\n");

    /*
     * why, when you print this out, do you get: 0, 1, 0, 1, (some crazy number)???
     * ANSWER: Because this array is only 2 ints long, you are starting to see the
     * beginning of the first array in memory, array1. If, for example, you changed
     * array1[0] to 42, the below  would print out:
     *      0 1 42 1 (some garbage value)
     */
    printf("array2 is: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%i ", array2[i]);
    }
    printf("\n");

    // this zeros all indexes that aren't initialized
    printf("array3 is: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%i ", array3[i]);
    }
    printf("\n");
}
