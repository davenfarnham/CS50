/*
 * By Daven Farnham (2014)
 *
 * Similar to increment, except you can can pass in multiple strings via
 * input.txt.
 *
 * ./input < input.txt
 */
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    for(int i = 0; i < 5; i++)
    {
        char* s = GetString();
        printf("You gave me %s\n", s);
    }
}
