/*
 * Sample program to illustrate switch statements as an alternative to if-elses.
 * Note, you can only use numbers with a switch statement; you can't switch on
 * strings.
 *
 * By Daven Farnham (2014)
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Hi!, give me a natural number less than 2 please!\n");
    int n = GetInt();

    switch (n) // this can only be an integer (think of it as fast index'ing, like an array)
    {
        case 0:
            printf("Uhh, is this a natural number? I'm not sure!\n");
            break; // without a break, things would 'fall through', printing 0, 1, etc until it hit a break or the end
        case 1:
            printf("Thanks for the 1\n");
            break;
        case 2:
            printf("Thanks for the 2\n");
            break;
        default:
            printf("Thanks for nothing!\n");
    }
}
