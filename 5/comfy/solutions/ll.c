/*
 * Daven Farnham (Fall 2015)
 *
 * Program to count the number of occurences of numbers in an
 * array.
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define DIGITS 10

typedef struct node {
    int i;
    struct node* next;
} node;

// prototypes
void create_ll(int* array, int size);
void count(void);
void free_hashtable();
void print_array(int* array, int size);

// your hashtable
node* hashtable[DIGITS];

int main(void)
{
    srand48(time(NULL));

    int array[SIZE];

    // place SIZE number of random values into the array
    for(int i = 0; i < SIZE; i++)
    {
	// value will be truncated to give you an int
        array[i] = drand48() * DIGITS;
    }

    printf("******** EXPECTED ********\n");

    for(int i = 0; i < DIGITS; i++)
    {
    	int counter = 0;
	for(int k = 0; k < SIZE; k++)
	{
	    if (array[k] == i)
	        counter++;
	}

	printf("You have %i numbers of value %i\n", counter, i);
    }

    printf("\n\n\n");

    printf("******** ACTUAL ********\n");

    // create a hashtable
    create_ll(array, SIZE);

    // count numbers
    count();

    // free mallocs
    free_hashtable();
}

void create_ll(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        node* node = malloc(sizeof(node));

        if(!node)
	{
	    printf("Could not malloc memory\n");
	    abort();
	}

	node->i = array[i];

	// complexity? O(1) since I'm prepending
	if(hashtable[array[i]] == NULL)
	{
            hashtable[array[i]] = node;
	    node->next = NULL;
	}
	else
	{
	    node->next = hashtable[array[i]];
	    hashtable[array[i]] = node;
	}
    }
}

// will be O(n) since I have to traverse each list
void count(void)
{
    for(int i = 0; i < DIGITS; i++)
    {
	// point to the start of the hashtable
        node* ptr = hashtable[i];

	int counter = 0;

        while(ptr != NULL)
        {
	    counter++;
	    ptr = ptr->next;
        }

	printf("You have %i numbers of value %i\n", counter, i);
    }
}

// also O(n)
void free_hashtable()
{
    for(int i = 0; i < DIGITS; i++)
    {
        node* ptr = hashtable[i];

	while(ptr != NULL)
	{
	    node* back = ptr;
	    ptr = ptr->next;
	    free(back);
	}
    }
}

void print_array(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
	printf("%i ", array[i]);
    }

    printf("\n");
}

