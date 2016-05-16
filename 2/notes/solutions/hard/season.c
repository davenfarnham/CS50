/*
 *
 * By Daven Farnham (2015)
 *
 * Solution: Create a function, in a separate file, to create the word "Meeseeks"
 * by indexing into cmd line arguments you pass into the function. You should
 * name your function "find()" and it should take 3 cmd line arguments (strings)
 * as parameters.
 *
 * After you've created your helper function, modify your header file "helper.h".
 * Change your Makefile if needed.
 *
 */

#include <stdio.h>
#include <string.h>
#include "helper.h"

// buffer for word (global)
char word[9];

int main (int argc, char* argv[])
{
	if (argc != 4)
	{
            printf ("Bad Arguments.\n");
	    return 1; 
	}

	if (strcmp(argv[1], "Rick") != 0)
	{
            printf ("Bad Arguments.\n");
	    return 1; 
	}

	if (strcmp(argv[2], "and") != 0)
	{
            printf ("Bad Arguments.\n");
	    return 1; 
	}

	if (strcmp(argv[3], "Morty") != 0)
	{
            printf ("Bad Arguments.\n");
	    return 1; 
	}

	if (strcmp(find(argv[0], argv[1], argv[3]), "Meeseeks") != 0)
		printf("I'm sorry!\n");
	else
		printf("Look at me!\n");
}

