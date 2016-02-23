/*
 * greedy.c: Pset 1. Tell how little change could be used to give money back.
 * Be careful of floating point imprecision.
 *
 * By Daven Farnham (2014)
 */

// include libraries
#include <stdio.h>
#include <math.h>
#include <cs50.h>

// define coin amounts
#define quarter 	25
#define dime 		10
#define nickel 		5
#define penny 		1

// main function
int main(int argc, char* argv[])
{
    // prompt user
	printf("Oh hai! How much change is needed? ");

	float change = GetFloat();

	while(change < 0)
	{
		printf("Woops! Try again please! ");
        change = GetFloat();
	}

    // use round function from math library to eliminate any floating point
    // inaccuracy.
	change = round(change*100);

	// counter for # of coins
	int counter = 0;

    // decrement change by 25; add 1 to counter
	while(change >= quarter)
	{
		change = change - quarter;
		counter++;
	}

    // decrement change by 10; add 1 to counter
	while(change >= dime)
	{
		change = change - dime;
		counter++;
	}

    // decrement change by 5; add 1 to counter
	while(change >= nickel)
	{
		change = change - nickel;
		counter++;
	}

    // add remainder to change
	counter = counter + change;

	printf("%i\n", counter);
}
