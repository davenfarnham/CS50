/*
 * Highlight that strings are really very similar to arrays. Also, point out the
 * common error of trying to change an immnutable string in read-only memory.
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "daven";

    // what will this print out??
    printf("%c%c%c%c%c\n", s[0], s[1], s[2], s[3], s[4]);

    // seg fault; a string declared like 's' is in read-only memory
    // s[0] = 'm';

    // this kind of string, however, is going to be on the stack and therefore mutable
    char s2[5] = {'d', 'a', 'v', 'e', 'n'};

    // will print out the same thing as 's'
    printf("%c%c%c%c%c\n", s2[0], s2[1], s2[2], s2[3], s2[4]);

    // "maven"
    s2[0] = 'm';
    printf("%c%c%c%c%c\n", s2[0], s2[1], s2[2], s2[3], s2[4]);

}
