/*
 * A helper file with all the sorts!
 *
 * By Daven Farnham (2014)
 */

#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** COMPARATIVE ***/

/*
 * Bubble Sort - larger values tend to bubble to the top. Here you have the size value
 * decreasing, which signifies that after each iteration of the loop, the far right side
 * is sorted. O(n^2) and Omega(n)
 */
int* bubble_sort(int array[], int size)
{
    for(int i = 0; i < size; size--)
    {
        int swaps = 0;

        for(int k = i; k < size - 1; k++)
        {
            if(array[k] > array[k + 1])
            {
                // swap values
                int tmp = array[k];
                array[k] = array[k + 1];
                array[k + 1] = tmp;
                swaps++;
            }
        }

        // if bubble sort iterated through all the elements at least once and didn't find anything
        // out of place, there are no swaps and everything must be sorted
        if(swaps == 0)
            break;
    }

    return array;
}

/*
 * Selection Sort - kind of like all the sorts, you're going to have a part of the array that is sorted and
 * another part of the array that is unsorted. What selection sort does is iterates over the unsorted part
 * of the array looking for the smallest element -> finds it -> then places it at the end of the sorted array
 * (since each next smallest element is going to be bigger than all elements currently in the sorted array).
 * O(n^2), Omega(n^2)
 */
int* selection_sort(int array[], int size)
{
    for(int k = 0; k < size; k++)
    {
        // initial minimum value
        int min = array[k];

        for(int i = k + 1 ; i < size; i++)
        {
            if (array[i] < min)
            {
                int tmp = array[i];
                array[i] = min;
                min = tmp;
                array[k] = min;
            }
        }
    }

    return array;
}

/*
 * Insertion Sort - place the next element in the unsorted array into the correct position in the sorted array.
 * O(n^2) and Omega(n)
 */
int* insertion_sort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        // next element that isn't sorted
        int next = array[i + 1];
        int min = i;

        // find where to place next - if next is never less than array[min]
        // then the while loop will never evaluate true, so you're just iterating
        // through the outer for loop (n)
        while(next < array[min] && min >= 0)
        {
            // swap
            int temp = array[min];
            array[min] = next;
            array[min + 1] = temp;

            // decrement counter
            min--;
        }

    }

    return array;
}

/*
 * Merge Sort [Divide and Conquer] - uses 2 fuctions: the first function breaks down the array into ever smaller chunks until you hit
 * a size of 1; while the second part compares the chunks and builds an array back up. This comparison algorithm is
 * about as fast as it gets Big O & Omega of nlog(n). STILL NEED TO LOOK AT, ERRORS WITH SOME BIG NUMBERS
 */
int* sort(int array[], int size)
{
    // if the array is only of size one, then return it since it is sorted
    if(size == 1)
        return array;
    else
    {
        int size1, size2; // size variables in case size is odd

        if(size % 2 != 0) // odd size
        {
            size1 = size/2;
            size2 = size/2 + 1;
        }
        else //even
        {
            size1 = size/2;
            size2 = size/2;
        }

        int* left_array = malloc(sizeof(int) * size1); // malloc memory for left array
        int* right_array = malloc(sizeof(int) * size2); // for right array

        int* sorted1 = sort(memcpy(left_array, array, sizeof(int) * size1), size1); // sort left side
        int* sorted2 = sort(memcpy(right_array, array + size1, sizeof(int) * size2), size2); // sort right

        // free the memory that was passed to you (assume it was malloc'ed!)
        free(array);

        // merge the sides
        return merge(sorted1, size1, sorted2, size2);
    }
}

int* merge(int array1[], int size1, int array2[], int size2)
{
    // malloc enough space for merged array
    int* merged = malloc((size1 + size2) * sizeof(int));

    // index for merged
    int k = 0;

    // loop to add things in to merged
    for(int i = 0, j = 0; i < size1 && j < size2; )
    {
        if(array1[i] < array2[j]) // left array element is smaller
        {
            *(merged + k++) = array1[i++];
        }
        else if(array1[i] > array2[j]) // right array element is smaller
        {
            *(merged + k++) = array2[j++];
        }
        else // elements in both array are equal
        {
            *(merged + k++) = array1[i++];
            *(merged + k++) = array2[j++];
        }

        // copy remainder if one side is done
        if(i == size1 && j != size2)
        {
            for( ; j < size2; j++, k++)
            {
                *(merged + k) = array2[j];
            }
        }
        // for the other side
        if(j == size2 && i != size1)
        {
            for( ; i < size1; i++, k++)
            {
                *(merged + k) = array1[i];
            }
        }
    }

    // free the two sides of what became the merged array (assume they are malloc'd!)
    free(array1);
    free(array2);

    return merged;

/*
 * Uncomment if you'd like to omit duplicates
 */

/*
    if(k == (size1 + size2))
        return merged; // no duplicates
    else
    {
            int* resized = malloc(sizeof(int) * k);
            memcpy(resized, merged, sizeof(int) * k);
            free(merged);
            return resized; //duplicates removed
    }
*/
}

/*
 * Heapsort Sort TODO
 */

/*** PARTITION ***/

/*
 * Quicksort Sort TODO
 */

/*** DISTRIBUTIVE ***/

/*
 * Radix Sort (completed in the 2015 material)
 */

/*
 * Bucket Sort TODO
 */

/*
 * Print out an array
 */

void print_array(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }

    printf("\n");
}
