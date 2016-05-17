/*
 * By Daven Farnham (2014)
 *
 * Print out a string to an output file: "./output < number.txt > answer.txt"
 * should print "Hey! your number was 50" in answer.txt
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number = GetInt();
    printf("Hey! your number was %i\n", number + 1);
}
