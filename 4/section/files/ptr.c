/*
 * ptr.c : illustrate how the type of pointer, be it a char*, int*, or whatever, affects how
 * you can increment the pointer value using array index notation.
 */

#include <stdio.h>

int main(void)
{
    // initialize an array
    int array[] = {1, 2, 3, 4, 5};

    // set an int pointer pointing to the beginning of the array
    int* ptr = array;

    // index the pointer, like an array
    for(int i = 0; i < 5; i++)
    {
        printf("%i\n", ptr[i]);
    }

    // this time, set a char* pointer pointing to the beginning of the array
    char* ptr2 = (char*) array;

    /*
     * index into the pointer, like an array. What do you notice?
     * Does this print out the same as the above for loop? Why?
     */
    for(int i = 0; i < 5; i++)
    {
        printf("%i\n", ptr2[i]);
    }
}
