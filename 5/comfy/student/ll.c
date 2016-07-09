// include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define a node struct
typedef struct node {
    int i;
    struct node* next;
} node;

// prototypes
void create_ll(int* array, int size);
void count(void);
void free_hashtable();

/* useful defined vales. SIZE is the number of elements in the array, while
 * DIGITS is the number of possilbe unique numbers. So, for example, if I had
 * 0, 1, 0, 1, 1, 0, 1, 1, 1, 0 then DIGITS == 2 and SIZE == 10
 */
#define SIZE 100
#define DIGITS 10

node* hashtable[DIGITS];

int main(void)
{
    // seed random number generator
    srand48(time(NULL));

    // temp array
    int array[SIZE];

    // place SIZE number of random values into the array
    for(int i = 0; i < SIZE; i++)
    {
	// values will be truncated to give you an int
        array[i] = drand48() * DIGITS;
    }

    printf("******** EXPECTED VALUES ********\n");

    // count the number of each kind of number in the array. Used as a check.
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

    printf("******** ACTUAL VALUES ********\n");

    // create a hashtable of lls
    create_ll(array, SIZE);

    // count numbers
    count();

    // free mallocs
    free_hashtable();
}

// create a hashtable, placing values into your table based on their value.
void create_ll(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
	node* ptr = malloc(sizeof(node));

	if(ptr == NULL)
	    abort();
    }
}

// traverse your linked lists, counting the number of nodes in each list. Print out totals.
void count(void)
{
    // TODO
}

// free the nodes you've malloc'ed from your hashtable.
void free_hashtable()
{
    // TODO
}
