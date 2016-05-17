/*
 * By Daven Farnham (2014)
 *
 * Use redirection to pass in a number from a text file and increment it. For example,
 * ./increment < my_number.txt
 *
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // it's gonna get the number from my_number.txt
    string s = GetString();
    int i = atoi(s);

    printf("%i", ++i);
}
