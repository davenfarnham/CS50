/*
 * name.c: Take in a one command line argument, the person's name, then
 * print out the last letter of that name.
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Sowwy!\n");
        return 1;
    }

    string s = argv[1];
    int end = strlen(s) - 1;

    printf("%c\n", s[end]);
}
