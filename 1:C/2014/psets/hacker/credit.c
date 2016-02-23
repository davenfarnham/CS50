/*
 * Notes: you can't determine the size of a dynamically allocated piece of memory with sizeof().
 * You can, however, find the size of a block of memory on the stack with sizeof()
 *
 * Notes: do structs get passed by reference? No, create a struct in main(), then a pointer
 * to that struct, which you'll pass around.
 *
 * By Daven Farnham (2014)
 */

/* Strategy: Take a number, break it up into parts to be indexed as an array. Then, add digits
 * as necessary.
 */

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// hold the broken up card inside a struct with its size
typedef struct array{

	int position;
	int* indexNumber;

} array;

// prototypes
void separate(long long x, array* number);
bool testCard(array* x);

// main
int main(int argc, char* argv[])
{

	printf("Oh, hai! What kind of CC would you like to test?\n");
	long long card = GetLongLong();
	// new struct
	array newCard;
	// ptr to that struct (use to pass values between functions)
	array* newCardptr = &newCard;
	// put number into index'able array
	separate(card, newCardptr);
	// test Cards
	if((newCardptr->position == 13 || newCardptr->position == 16) &&
	    newCardptr->indexNumber[newCardptr->position-1] == 4)
	{
		if(testCard(newCardptr))
			printf("VISA\n");
	}
	else if(newCardptr->position == 15)
	{
		int temparray[2];
		temparray[0] = newCardptr->indexNumber[newCardptr->position-1];
		temparray[1] = newCardptr->indexNumber[newCardptr->position-2];
		int temp = temparray[0] * 10 + temparray[1];
		if(temp == 34 || temp == 37)
			if(testCard(newCardptr))
				printf("AMEX\n");
	}
	else if(newCardptr->position == 16)
	{
		int temparray[2];
		temparray[0] = newCardptr->indexNumber[newCardptr->position-1];
		temparray[1] = newCardptr->indexNumber[newCardptr->position-2];
		int temp = temparray[0] * 10 + temparray[1];
		if(temp == 51 || temp == 52 || temp == 53 || temp == 54 || temp == 55)
			if(testCard(newCardptr))
				printf("MASTERCARD\n");
	}
	else
			printf("INVALID\n");

    	free(newCardptr->indexNumber);

	return 0;
}

// turn int into index'able array
void separate(long long x, array* number)
{
	// initialize a pointer to memory
	int* array = malloc(sizeof(int));
	// beginning position in the array
	int position = 0;

	do
	{
		// take off the last digit, store into array
		array[position] = x % 10;
		// increment i
		position++;
		// change x
		x = x / 10;
		// change size of array
		array = realloc(array, (position + 1) * sizeof(int));
	} while (x > 0);

    	// points to the end of the array
	number->position = position;
	// structs's indexNumber is the CC's # in an index'able array
	number->indexNumber = array;

	return;
}


bool testCard(array* x)
{
	int position = x->position;
	int* array = x->indexNumber;

	// American Express
	// counter holds summation of digits that were multiplied by two
	int counter = 0;

	// multiply every other digit by 2, then sum their DIGITS
	for(int h = 1; h < position; h=h+2)
	{
		int sum = array[h] * 2;
		if(sum > 9)
		{
			counter = counter + sum % 10;
			counter = counter + sum / 10;
		}
		else
			counter = sum + counter;
	}

    	// add to previous sum the sum of remaining digits
	int secondCounter = 0;
	for(int h = 0; h < position; h=h+2)
	{
		int sum = array[h];
		secondCounter = secondCounter + sum;
	}

    	// if mod 10 = 0, then true
	if((secondCounter + counter)%10 == 0)
		return TRUE;
	else
		return FALSE;
}
