/*
 * ask for a command line argument; specifically an int
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    // why do I have to do this?
    if(argc != 2)
    {
        printf("Sorry! Not enough arguments!\n");
        return 1;
    }

    int number = atoi(argv[1]); // note, it isn't easy to check whether input is an int or string
    printf("Hi! You gave me a %d\n", number);
}
