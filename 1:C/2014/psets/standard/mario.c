/*
 * mario.c: Pset 1. Print out a mario pyramid with hashes
 *
 * By Daven Farnham (2014)
 */

// include standard library
#include <stdio.h>
// include cs50 library
#include <cs50.h>

// prototype
void printPyramid(int x);

// main function
int main(int argc, char* argv[])
{
    // initialize size to zero
    int size = 0;

    // a do-while loop, 'cause why not!?
	do{
        // prompt user
        printf("Height: ");
        // get size of pyramid
        size = GetInt();
	} while(size < 0 || size > 23); // if size is negative or greater than 23, try again

	// print pyramid
	printPyramid(size);
}

// function to print our pyramid
void printPyramid(int x)
{
	if(x == 0)
		return;
	else
	{
		for(int i = 0; i < x; i++)
		{
		    // print out spaces
			for(int h = 1; h < (x - i); h++)
				printf(" ");
			// print out hashes
			for(int k = 0; k <= i+1; k++)
				printf("#");
			// print out newline
			printf("\n");
		}
	}
}
