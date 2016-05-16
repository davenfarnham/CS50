/*
 * Recursive program to find a factorial. Should return 120
 *
 * By Daven Farnham (2014)
 */

#include <stdio.h>

int factorial(int number);

int main(void)
{
    // hardcode 5! as factorial you want to find
    int number = 5;

    // run function
    int answer = factorial(number);

    // print answer
    printf("%i\n", answer);
}

int factorial(int number)
{
    if(number == 1)
        return 1;
    else
        return number * factorial(number - 1); //  1 * number (2) * number (3) * number (4) * number (5);
}
