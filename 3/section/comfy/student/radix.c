/*
 *
 * Daven Farnham (2015)
 *
 * Radix Sort: O(wn).
 *
 * What are some problems with this implementation? Time wise? Space wise?
 *
 */

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "helpers.h"

// size of array (and each queue)
#define CAPACITY 25
// word size
#define LENGTH 3
#define ARRAYSIZE 25
#define DIGITS 10

// define a queue data structure
typedef struct queue
{
	// number of elements in the queue
	int size;

	// array to hold elements
	int* q;

	// index of head (front of queue)
	int head;

	// index of tail (back of queue)
	int tail;
} queue;

// push element onto queue
bool push (queue* ptr, int value)
{
	// TODO
}

// pop element off queue
int pop (queue* ptr)
{
	// TODO
}

// takes a number n to the p (recursively)
int exponent(int n, int p)
{
        if (p == 0)
          return 1;

        return n * exponent (n, (p-1));
}

// return the digit, out of number, in the 'position' place
int digit(int number, int position)
{
        if (position == 0)
          return number % 10;

        return (number / (exponent (10, position)) % (exponent (10, position)));
}

int* sort(int* a, queue* b[])
{
    for (int h = 0; h < LENGTH; h++)
    {
        for (int i = 0; i < ARRAYSIZE; i++)
        {
                int lsd = digit(*(a + i), h);
                queue* ptr = b[lsd];
                push(ptr, *(a + i));
        }


        for(int i = 0, k = 0; i < DIGITS; i++)
        {
                queue* ptr = b[i];
                int s = (ptr -> size);
                for (int l = 0; l < s; l++)
                    *(a + (k++)) = pop(ptr);
        }
    }

        return a;
}

int main (void)
{
        queue* buckets[DIGITS];;

        // initialize values
        for (int i = 0; i < DIGITS; i++)
        {
            buckets[i] = malloc(sizeof(queue));
            queue* ptr = buckets[i];
            ptr -> size = 0;
            (ptr -> q) = malloc(sizeof(int) * CAPACITY);
            (ptr -> head) = 0;
            (ptr -> tail) = 0;
        }

	int* array = malloc(sizeof(int) * ARRAYSIZE);

	// create an array of random values
        srand(time(NULL));

        for (int i = 0; i < ARRAYSIZE; i++)
            *(array + i) = (rand() % 100);

        int* ret_array = sort(array, buckets);

	print_array(ret_array, ARRAYSIZE);
}
