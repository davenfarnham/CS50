/*
 * Similar to cline.c but with 4 arguments instead of only 2
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        printf("Sorry! Not enough arguments! [int] [name] [string]\n");
        return 1;
    }

    int number = atoi(argv[1]);
    printf("Hi! My name is %s; I like %s and my favorite number is %i!\n", argv[2], argv[3], number);
}
