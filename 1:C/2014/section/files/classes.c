/*
 * classes.c: Use a for loop to print out the contents of an array
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string classes[4];
    classes[0] = "CS50";
    classes[1] = "stat110";
    classes[2] = "stat139";
    classes[3] = "applied math 121";

    printf("My students like science classes, like: ");

    for(int i = 0; i < 4; i++)
    {
        printf("%s ", classes[i]);
    }

    printf("\n");
}
