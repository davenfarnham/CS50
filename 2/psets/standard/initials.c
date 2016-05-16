/*
 * Print out the initials of a name capitalized
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = GetString();

    int len = strlen(s);

    // assume first letter and capitalize
    printf("%c", toupper(s[0]));

    for(int i = 1; i < len - 1; i++)
    {
        // upper case any letter after a space
        if(s[i] == ' ')
        printf("%c", toupper(s[i+1]));
    }

    printf("\n");
}
