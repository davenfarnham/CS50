#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define struct for your trie
// TODO

// prototypes
void add_number(row* origin, int number);
void search(row* origin, int search);

// size of array
#define SIZE 8

int main(void)
{
    row* origin = malloc(sizeof(row));

    int array[SIZE] = {10, 67, 5, 198, 4, 0, 200, 1476};

    for(int i = 0; i < SIZE; i++)
    {
        add_number(origin, array[i]);
    }

    printf("******** TESTING ********\n");
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

// add a number to the trie
void add_number(row* origin, int number)
{
    // TODO
}

// search for a number in the trie
void search(row* origin, int search)
{
    // TODO
}
