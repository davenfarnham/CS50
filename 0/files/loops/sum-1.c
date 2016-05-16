/*
 * Another example of using both an iterative and recursive approach to sum numbers in an array.
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>

int sum(int x, int y[]);

int main(void)
{
    // create array
    int array[] = {1,2,3,4,5,6,7,8,9,10};

    /*
     * I do this because I don't want to hardcode the size of the array. sizeof() simply returns
     * the number of bytes in the data type (like int, char, etc) or data structure (array)
     */
    int size = sizeof(array)/sizeof(int);

    // Recursive approach
    printf("Recursive sum = %i\n", sum(size - 1, array));

    int counter = 0;

    // Iterative approach
    for(int i = 0; i < size; i++)
    {
        counter = counter + array[i];
    }

    printf("Iterative sum = %i\n", counter);

    // that's all!
    return 0;
}

// pass in size of array and the array
int sum(int x, int y[])
{
    /*
     * This is the base case. Since we are using x to index into our array, once we
     * get to -1, we want to start returning out of our recursion.
     */
    if (x < 0)
        return 0;
    /*
     *  Recursive step; continuously call sum() until you hit the base case, then start 
     *  adding back y[x].
     */
    else
        return sum(x-1, y) + y[x];
}
