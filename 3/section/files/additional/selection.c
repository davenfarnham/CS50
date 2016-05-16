#include <stdio.h>

#define SIZE 10

/******************************************************************************
 * Selection sort, in this version, has space complexity O(n) and time        *
 * complexity O(n^2) where n is the length of the array. Selection sort       *
 * builds the final sorted array by removing, one at a time, the smallest     *
 * element in the unsorted array and placing it at the head of the sorted     *
 * array.                                                                     *
 *                                                                            *
 *  E.G.                                                                      *
 *      [50, 1, 42, 4, 51]                                                    *
 *                      ->                                                    *
 *                          [1, 50, 42, 4, 51]                                *
 *                          [1, 4, 42, 50, 51]                                *
 *                          [1, 4, 42, 50, 51]                                *
 *                          [1, 4, 42, 50, 51]                                *
 *                                                                            *
 * Note: the same trick used with bubble sort wouldn't optimize selection     *
 * sort. An array like [1, 3, 2] would have no swaps the first run through,   *
 * however, it is obviously not sorted.                                       *
 ******************************************************************************/

void sort(int array[], int size);
void print(int array[]);

int main(void)
{
    // sample array
    int array[SIZE] = {55, 10, 50, 41, 33, 4, 3, 1, 22, 24};

    // print out initial array
    printf("Initial: ");
    print(array);

    // selection sort
    sort(array, SIZE);

    // print out sorted array
    printf("Sorted: ");
    print(array);
}

void sort(int array[], int size)
{
    // sorted part of array
    for(int i = 0; i < size - 1; i++)
    {
        // smallest element and its position in sorted array
        int smallest = array[i];
        int position = i;

        // unsorted part of array
        for(int k = i + 1; k < size; k++)
        {
            // find the next smallest element
            if(array[k] < smallest)
            {
                smallest = array[k];
                position = k;
            }
        }

        // swap
        int temp = array[i];
        array[i] = smallest;
        array[position] = temp;
    }
}

// print out array
void print(int array[])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}
