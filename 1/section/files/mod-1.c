/*
 * mod2.c: Take two command line arguments: Index & Name. Index into Name,
 * but use mod to protect against indexing past the end of the array
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // protect against them not giving me the right # of cmd line args
    if(argc != 3)
    {
        printf("Usage: ./mod2 Index Name\n");
        return 1;
    }

    // take name from command line
    char* s = argv[2];

    // convert string from command line to int
    int number = atoi(argv[1]);

    // find the end of string
    int end = strlen(s);

    // print it out!
    printf("You chose %c!\n", s[number%end]);
}
