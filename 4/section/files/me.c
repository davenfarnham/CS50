/*
 * By Daven Farnham (2014)
 *
 * Similar to both input.c and increment.c
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = GetString();
    int i = GetInt();

    printf("%s's favorite number is %i\n", s, i);
}
