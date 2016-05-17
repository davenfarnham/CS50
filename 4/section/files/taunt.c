/*
 * By Daven Farnham (2014)
 *
 * Illustrate how cs50's library works - I think GetInt() imposes an
 * upper bound on the integer value input.
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = GetInt();

    printf("Na na, you gave me less than %i!\n", i);
}
