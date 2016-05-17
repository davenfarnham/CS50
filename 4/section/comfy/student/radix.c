/*
 *
 * Daven Farnham (Fall 2015)
 *
 * Radix Sort: O(wn). In this implementation, I use queues as temporary storage.
 * This is an updated example from last week. There are no longer any memory leaks.
 * The queues also change size if you try to push more elements onto them. The only things
 * to change are ARRAYSIZE, LENGTH, and the modded value when you're placing elements in the
 * array in the main function.
 *
 * Time complexity will be (ARRAYSIZE * LENGTH).
 *
 */

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "helpers.h"

// size of each queue at start
#define CAPACITY 20
// word size (number of digits)
#define LENGTH 3
// size of input array
#define ARRAYSIZE 25
// you only have 10 digits
#define DIGITS 10

// define a queue data structure
typedef struct queue
{
	// # of elements in queue
	int size;

	// pointer to another array
	int* q;

	// index of head
	int head;

	// index of tail
	int tail;

	// current max;
	int max;
} queue;

// prototypes
bool enqueue (queue* ptr, int value);
int dequeue (queue* ptr);
int exponent(int n, int p);
int digit(int number, int position);
int* sort(int* a, queue* b[]);

int main (void)
{
	// an array of pointers to queues
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
            (ptr -> max) = CAPACITY;
        }

	// malloc an array to place elements in
	int* array = malloc(sizeof(int) * ARRAYSIZE);

	// see random # generator
        srand(time(NULL));

	// place elements in array
        for (int i = 0; i < ARRAYSIZE; i++)
            *(array + i) = (rand() % 1000);

	// print out unsorted array
	print_array(array, ARRAYSIZE);

	// sort array
        int* ret_array = sort(array, buckets);

	// print out sorted array
	print_array(ret_array, ARRAYSIZE);

	// free all arrays (acting as queues)
	for (int i = 0; i < DIGITS; i++)
	{
	    queue* ptr = buckets[i];
	    free(ptr -> q);
	    free(ptr);
	}

	// free return array
	free (array);
}

// push elements onto the back of queue (called enqueue)
bool enqueue (queue* ptr, int value)
{
	if (ptr -> size == ptr -> max)
	    return false;

	(ptr -> size)++;
	*((ptr -> q) + (ptr -> tail)) = value;

	ptr -> tail = ((ptr -> tail) + 1) % (ptr -> max);

	return true;
}

// pop elements off the front of the queue (dequeue)
int dequeue (queue* ptr)
{
	if (ptr -> size == 0)
	{
		printf ("No more elements in queue\n");
		abort();
	}

	int value = *((ptr -> q) + (ptr -> head));

	(ptr -> size)--;

        ptr -> head = ((ptr -> head) + 1) % (ptr -> max);

	return value;
}

// useful helper function, n^p
int exponent(int n, int p)
{
        if (p == 0)
          return 1;

        return n * exponent (n, (p-1));
}

/* returns the digit from number in place position.
 * For example, digit(121, 1) == 2. */
int digit(int number, int position)
{
        if (position == 0)
          return number % 10;

        return (number / (exponent (10, position)) % (exponent (10, position)));
}

// sort into bins ** SUBSTANTIAL POINTER ARITHMETIC **
int* sort(int* a, queue* b[])
{
    for (int h = 0; h < LENGTH; h++)
    {
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		int lsd = digit(*(a + i), h);
		queue* ptr = b[lsd];

		// if the queue in the bucket is full, realloc
		if ((ptr->size) == (ptr->max))
		{
		    // realloc space (add on 20 more int slots)
		    (ptr->q) = realloc((ptr->q), sizeof(int) * (ptr->size + CAPACITY));

		    // check realloc was successful
		    if((ptr->q) == NULL)
	 	    {
			printf("Problem allocating more memory\n");
			abort();
		    }

		    // change max size
		    (ptr -> max) = (ptr -> max) + CAPACITY;

		    memcpy(ptr->q + (ptr->head + CAPACITY), ptr->q + ptr->head, sizeof(int) * (ptr->size - ptr->head));

		    ptr -> head = (ptr -> head) + CAPACITY;
		}

		// push element onto the back of the queue
		if(!enqueue(ptr, *(a + i)))
		{
		    printf("Problem adding to queue\n");
		    abort();
		}
	}


	for(int i = 0, k = 0; i < DIGITS; i++)
	{
		queue* ptr = b[i];
		int s = (ptr -> size);

		for (int l = 0; l < s; l++)
		    *(a + (k++)) = dequeue(ptr);
	}
    }

    return a;
}

