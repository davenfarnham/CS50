#include <stdio.h>

#define SIZE 10

/******************************************************************************
 * Insertion sort, in this version, has space complexity O(n) and time        *
 * complexity of O(n^2) where n is the length of the array. Insertion sort    *
 * builds the final sorted array one element at a time by removing, one at a  *
 * time, elements in the unsorted array and placing them in their correct     *
 * position in the sorted array.                                              *
 *                                                                            *
 *  E.G.                                                                      *
 *      [2, 8, 1, 4, 3]                                                       *
 *                      ->                                                    *
 *                          [2, 8, 1, 4, 3]                                   *
 *                          [1, 2, 8, 4, 3]                                   *
 *                          [1, 2, 4, 8, 3]                                   *
 *                          [1, 2, 3, 4, 8]                                   *
 ******************************************************************************/

// prototypes
void sort(int array[], int length);
void print(int array[]);

int main(void)
{
    // sample array
    int array[SIZE] = {3, 7, 4, 9, 5, 2, 6, 1, 50, 0};

    // print initial array
    printf("Initial: ");
    print(array);

    // insertion sort
    sort(array, SIZE);

    // print sorted array
    printf("Sorted: ");
    print(array);
}

// insertion sort
void sort(int array[], int length)
{
    // go through unsorted list
    for(int k = 0; k < length - 1; k++)
    {
        // choose element right outside sorted part of list
        int insert = array[k+1];

        // see if 'insert' is smaller than any element in sorted list
        for(int i = 0; i < k + 1; i++)
        {
            // if element is smaller than some element in sorted list
            if(insert < array[i])
            {
                int temp = array[i];

                // shift everything down
                for(int h = i; h <= k; h++)
                {
                    // store array[h+1] in temp2
                    int temp2 = array[h+1];
                    // replace array[h+1] with the item before it
                    array[h+1] = temp;
                    // store in temp the element array[h+1], which was stored
                    // in temp2; remember array[h+1] was already replaced above
                    temp = temp2;
                }

                // insert new element
                array[i] = insert;

                // break out of loop
                break;
            }
        }
    }
}

// helper function to print out array
void print(int array[])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}
