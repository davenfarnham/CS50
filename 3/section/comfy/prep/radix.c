/*
 *
 * Daven Farnham (2015)
 *
 * Radix Sort: O(wn).
 *
 */

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// size of array (and each queue)
#define CAPACITY 25

// word size
#define LENGTH 3
#define ARRAYSIZE 25
#define DIGITS 10

// define a queue data structure
typedef struct queue
{
	int size;

	int* q;

	// index of head
	int head;

	// index of tail
	int tail;
} queue;

// takes a pointer to a queue
bool push (queue* ptr, int value)
{
	if (ptr -> size == CAPACITY)
	    return false;

	(ptr -> size)++;
	*((ptr -> q) + (ptr -> tail)) = value;

	ptr -> tail = ((ptr -> tail) + 1) % CAPACITY;

	return true;
}

int pop (queue* ptr)
{
	if (ptr -> size == 0)
	{
		printf ("No more elements in queue\n");
		abort();
	}

	int value = *((ptr -> q) + (ptr -> head));

	(ptr -> size)--;

        ptr -> head = ((ptr -> head) + 1) % CAPACITY;

	return value;
}

int exponent(int n, int p)
{
        if (p == 0)
          return 1;

        return n * exponent (n, (p-1));
}

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

        int array[ARRAYSIZE] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 10, 11, 12, 67, 51, 99, 44, 32, 27, 81, 76, 14, 100, 673, 144, 500};

        int* ret_array = sort(array, buckets);

        for (int i = 0; i < ARRAYSIZE; i++)
                printf("%i ", *(ret_array + i));

        printf("\n");
}
