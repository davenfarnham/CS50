/*
 * Daven Farnham (2015)
 *
 * Program to insert numbers into a trie.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct row {
    // an array for all digits
    struct row* list[10];
    // end to demarcate a number
    bool number;
} row;

void add_number(row* origin, int number);
void search(row* origin, int search);
void zero(row* ptr);

#define SIZE 8
#define NULLITY 0

int main(void)
{
    row* origin = malloc(sizeof(row));

    // since for some reason my machine doesn't NULL pointers at
    // the beginning
    zero(origin);

    int array[SIZE] = {10, 67, 5, 198, 4, 0, 200, 1476};

    for(int i = 0; i < SIZE; i++)
    {
        add_number(origin, array[i]);
    }

    printf("******** TESTING ********\n");
    search(origin, 0);
    search(origin, 0);
    search(origin, 0);
    search(origin, 10000);
    search(origin, 198);
    search(origin, 10);
    search(origin, 10);
    search(origin, 10);
    search(origin, 67);
    search(origin, 5);
    search(origin, 4);
    search(origin, 200);
    search(origin, 199);
}

void add_number(row* origin, int number)
{
    // set a pointer pointing to the initial starting row
    row* ptr = origin;

    // for when the number is 0
    if(!number)
    {
        if(!(ptr->list[number]))
        {
            ptr -> list[number] = malloc(sizeof(row));
            ptr = ptr->list[number];
        }
        else
            ptr = ptr->list[number];

        ptr->number = true;
	    return;
    }

    // start with a pointer to the first row
    while(number > 0)
    {
	int insert = number % 10;
	number = number / 10;

	if(!(ptr->list[insert]))
	{
	    // create a new row
	    ptr->list[insert] = malloc(sizeof(row));
	    // change pointer
	    ptr = ptr->list[insert];
	    zero(ptr);
	}
	else
	    ptr = ptr->list[insert];
    }

    ptr->number = true;
}

void search(row* origin, int search)
{
    row* ptr = origin;

    if (!search)
        ptr = ptr->list[search];

    // start with a pointer to the first row
    while(ptr != NULL && search > 0)
    {
        int insert = search % 10;
	search = search / 10;

        if(!(ptr->list[insert]))
	{
	    printf("Not in trie! \n");
	    return;
	}
        else
	    ptr = ptr->list[insert];
    }

    if(!ptr || !(ptr->number))
        printf("Not in trie! \n");
    else
        printf("In trie! \n");
}

// because my computer seems to be dumb and doesn't NULL out pointers to 0?
void zero(row* ptr)
{
    for(int i = 0; i < 10; i++)
        ptr->list[i] = NULLITY;
}
