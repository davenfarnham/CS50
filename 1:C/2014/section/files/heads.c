/*
 * An example of a string array with heads
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string heads[3];
    heads[0] = "rob";
    heads[1] = "gabe";
    heads[2] = "daven";

    printf("The CS50 heads are %s, %s, %s\n", heads[0], heads[1], heads[2]);
}
