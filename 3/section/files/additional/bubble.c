#include <stdio.h>

#define SIZE 10

/******************************************************************************
 * Bubble Sort runs in O(n) space complexity and O(n^2) time complexity. It   *
 * works on an array of size n by iterating across the unsorted part of the   *
 * array, switching adjacent items that are out of place. In this way, larger *
 * elements tend to 'bubble' to the top. (or, if you were to flip the list,   *
 * larger elements 'sink' to the bottom, AMIRITE ROB)                          *
 *                                                                            *
 * E.G.                                                                       *
 *      [4, 1, 7, 10, 3]                                                      *
 *                       ->                                                   *
 *                          [1, 4, 7, 3, 10]                                  *
 *                          [1, 4, 3, 7, 10]                                  *
 *                          [1, 3, 4, 7, 10]                                  *
 *                          [1, 3, 4, 7, 10]                                  *
 *****************************************************************************/

// prototypes
void sort(int array[], int n);
void print(int array[]);

int main(void)
{
    // sample array
    int array[SIZE] = {1, 4, 10, 11, 2, 50, 51, 3, 32, -15};

    // print initial array
    printf("Initial: ");
    print(array);

    // bubble sort
    sort(array, SIZE);

    // print sorted array
    printf("Sorted: ");
    print(array);
}

// bubble sort
void sort(int array[], int n)
{
    // to move an element from one end to the other in an array of size n,
    // you only need n - 1 moves; cycle through array.
    for(int k = 0; k < n - 1; k++)
    {
        // optimize; check if there are no swaps
        int swaps = 0;

        // switch adjacent elements if out of order
        for(int i = 0; i < n - 1 - k; i++)
        {
            if(array[i] > array[i + 1])
            {
                int temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;

                swaps++;
            }
        }

            if(!swaps)
                break;
    }
}

// print out sorted array
void print(int array[])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}
